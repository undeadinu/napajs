#pragma once

#include <napa/v8-helpers/string.h>
#include <utility>

namespace napa {
namespace v8_helpers {
    /// <summary> Unified method signature for convert V8 value to C++ types. </summary>
    template <typename T>
    inline T V8ValueTo(const v8::Local<v8::Value>& value) {
        static_assert(sizeof(T) == -1, "No specilization exists for this type");
    }

    /// <summary> Convert a v8 value to std::string. </summary>
    template <>
    inline std::string V8ValueTo(const v8::Local<v8::Value>& value) {
        v8::String::Utf8Value utf8Value(value);
        return *utf8Value;
    }

    /// <summary> Convert a v8 value to a Utf8String. </summary>
    template <>
    inline Utf8String V8ValueTo(const v8::Local<v8::Value>& value) {
        return Utf8String(value);
    }
}
}