#include "JFrameProcessor.h"
#include "JSharedArray.h"
#include "JVisionCameraProxy.h"
#include "JVisionCameraScheduler.h"
#include "VideoPipeline.h"
#include "VisionCameraProxy.h"
#include <fbjni/fbjni.h>
#include <jni.h>

//static int *p;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void*) {
  return facebook::jni::initialize(vm, [] {
    vision::VisionCameraInstaller::registerNatives();
    vision::JVisionCameraProxy::registerNatives();
    vision::JVisionCameraScheduler::registerNatives();
    vision::VideoPipeline::registerNatives();
#if VISION_CAMERA_ENABLE_FRAME_PROCESSORS
    vision::JFrameProcessor::registerNatives();
    vision::JSharedArray::registerNatives();
#endif

//      __android_log_print(ANDROID_LOG_INFO, "VisionCamera", "Sanitizer Address: Start Test ...");
//
//      // 栈缓冲区溢出
//      int stack_array[100];
//      stack_array[1] = 0;
//      int b = stack_array[100];  // BOOM
//      __android_log_print(ANDROID_LOG_INFO, "VisionCamera", "Sanitizer Address: stack buffer overflow -> %d", b);
//
//      // 堆内存溢出
//      int *array = new int[100];
//      array[0] = 0;
//      int res = array[100 + 32];  // BOOM
//      delete [] array;
//      __android_log_print(ANDROID_LOG_INFO, "VisionCamera", "Sanitizer Address: heap memory overflow -> %d", res);
//
//      // 使用已释放的指针
//      int *list = new int[1024];
//      list[0] = 11;
//      delete[] list;
//      __android_log_print(ANDROID_LOG_INFO, "VisionCamera",
//                          "Sanitizer Address: UseAfterFree list[0]=%d, list[1024]=%d", list[0], list[1024]);
//
//      // 重复释放指针
//      int *arr = new int[1024];
//      arr[0] = 11;
//      delete[] arr;
//      delete[] arr;
//      __android_log_print(ANDROID_LOG_INFO, "VisionCamera", "Sanitizer Address: Double free arr[0]=%d", arr[0]);
//
//      // 作用域之外使用其指针
//      {
//          int a = 0;
//          p = &a;
//      }
//      *p = 1111;
//      __android_log_print(ANDROID_LOG_INFO, "VisionCamera", "Sanitizer Address: UseAfterScope *p=%d", *p);
//
//      // 分配内存没被释放
//      void *ptr = malloc(sizeof(int));
//      __android_log_print(ANDROID_LOG_INFO, "VisionCamera", "Sanitizer Address: MemoryLeaks %p;", ptr);

  });
}
