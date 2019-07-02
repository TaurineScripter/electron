// Copyright (c) 2019 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

// TODO(deermichel): remove _gin suffix after removing mate

#ifndef SHELL_COMMON_GIN_CONVERTERS_VALUE_CONVERTER_GIN_H_
#define SHELL_COMMON_GIN_CONVERTERS_VALUE_CONVERTER_GIN_H_

#include "gin/converter.h"

namespace base {
class DictionaryValue;
class ListValue;
class Value;
}  // namespace base

namespace gin {

template <>
struct Converter<base::DictionaryValue> {
  static bool FromV8(v8::Isolate* isolate,
                     v8::Local<v8::Value> val,
                     base::DictionaryValue* out);
  static v8::Local<v8::Value> ToV8(v8::Isolate* isolate,
                                   const base::DictionaryValue& val);
};

template <>
struct Converter<base::Value> {
  static bool FromV8(v8::Isolate* isolate,
                     v8::Local<v8::Value> val,
                     base::Value* out);
  static v8::Local<v8::Value> ToV8(v8::Isolate* isolate,
                                   const base::Value& val);
};

template <>
struct Converter<base::ListValue> {
  static bool FromV8(v8::Isolate* isolate,
                     v8::Local<v8::Value> val,
                     base::ListValue* out);
  static v8::Local<v8::Value> ToV8(v8::Isolate* isolate,
                                   const base::ListValue& val);
};

}  // namespace gin

#endif  // SHELL_COMMON_GIN_CONVERTERS_VALUE_CONVERTER_GIN_H_
