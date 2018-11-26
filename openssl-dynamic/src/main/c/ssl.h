/*
 * Copyright 2017 The Netty Project
 *
 * The Netty Project licenses this file to you under the Apache License,
 * version 2.0 (the "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at:
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */
#ifndef NETTY_TCNATIVE_SSL_H_
#define NETTY_TCNATIVE_SSL_H_

#if !defined(OPENSSL_NO_TLS1_3) && defined(OPENSSL_IS_BORINGSSL)

//
// The OpenSSL and BoringSSL APIs for TLS 1.3 Early Data are slightly
// different. To make things a bit easier I'm re-implementing the given
// OpenSSL API in BoringSSL using boring's primitives.
//

#ifndef SSL_READ_EARLY_DATA_ERROR
#define SSL_READ_EARLY_DATA_ERROR   0
#endif

#ifndef SSL_READ_EARLY_DATA_SUCCESS
#define SSL_READ_EARLY_DATA_SUCCESS 1
#endif

#ifndef SSL_READ_EARLY_DATA_FINISH
#define SSL_READ_EARLY_DATA_FINISH  2
#endif

#ifndef SSL_EARLY_DATA_NOT_SENT
#define SSL_EARLY_DATA_NOT_SENT     0
#endif

#ifndef SSL_EARLY_DATA_REJECTED
#define SSL_EARLY_DATA_REJECTED     1
#endif

#ifndef SSL_EARLY_DATA_ACCEPTED
#define SSL_EARLY_DATA_ACCEPTED     2
#endif

int SSL_write_early_data(SSL *s, const void *buf, size_t num, size_t *written);
int SSL_read_early_data(SSL *s, void *buf, size_t num, size_t *readbytes);
#endif

// JNI initialization hooks. Users of this file are responsible for calling these in the JNI_OnLoad and JNI_OnUnload methods.
jint netty_internal_tcnative_SSL_JNI_OnLoad(JNIEnv* env, const char* packagePrefix);
void netty_internal_tcnative_SSL_JNI_OnUnLoad(JNIEnv* env);
#endif /* NETTY_TCNATIVE_SSL_H_ */
