LOCAL_PATH := $(call my-dir)

# Define the native library (libnativeaudio)
include $(CLEAR_VARS)
LOCAL_MODULE := libnativeaudio
LOCAL_SRC_FILES := src/native-lib.cpp
LOCAL_SHARED_LIBRARIES := liblog libnativehelper libhidlbase libutils hardware_interfaces_custommedia_1_0
LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/src \
    frameworks/native/include \
    system/libhidl/transport/include \
    hardware/interfaces/custommedia/1.0
LOCAL_CFLAGS := -Wall -Werror
include $(BUILD_SHARED_LIBRARY)

# Define the native activity app
include $(CLEAR_VARS)
LOCAL_MODULE := NativeAudioPlayer
LOCAL_SRC_FILES := $(call all-cpp-files-under, src)
LOCAL_SHARED_LIBRARIES := \
    liblog \
    libutils \
    android.hardware.custommedia@1.0
LOCAL_MODULE_TAGS := optional
LOCAL_CERTIFICATE := platform
LOCAL_MODULE_CLASS := APPS
LOCAL_SDK_VERSION := current
include $(BUILD_NATIVE_ACTIVITY)
