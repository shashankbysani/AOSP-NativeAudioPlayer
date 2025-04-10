#include <android/native_activity.h>
#include <android/log.h>
#include <hardware/custommedia.h>  // Adjust based on your HAL header
#include <hidl/Status.h>
#include <utils/StrongPointer.h>

#define LOG_TAG "NativeAudioPlayer"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

using namespace android;
using namespace hardware::custommedia::V1_0;

static sp<ICustomMedia> getCustomMediaService() {
    sp<ICustomMedia> service = ICustomMedia::getService();
    if (service == nullptr) {
        LOGE("Failed to get ICustomMedia service");
    }
    return service;
}

static void playAudioUsingHAL() {
    sp<ICustomMedia> service = getCustomMediaService();
    if (service != nullptr) {
        auto result = service->playAudio();  // Replace with your HAL method
        if (!result.isOk()) {
            LOGE("HAL playAudio failed: %s", result.description().c_str());
        } else {
            LOGI("Audio played successfully via HAL");
        }
    }
}

// Native activity entry point
void ANativeActivity_onCreate(ANativeActivity* activity, void* savedState, size_t savedStateSize) {
    LOGI("NativeAudioPlayer started");
    playAudioUsingHAL();
    // Minimal activity: no UI, just trigger HAL audio playback
}
