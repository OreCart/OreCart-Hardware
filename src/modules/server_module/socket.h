#pragma once

#define TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256	0xc02B
#define TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384	0xC030
#define TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256	0xC02F
#define TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384 0xC024
#define TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA	0xC00A
#define TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256	0xC023
#define TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA	0xC009
#define TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA		0xC014
#define TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256	0xC027
#define TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA		0xC013
#define TLS_PSK_WITH_AES_256_CBC_SHA			0x008D
#define TLS_PSK_WITH_AES_128_CBC_SHA256			0x00AE
#define TLS_PSK_WITH_AES_128_CBC_SHA			0x008C
#define TLS_PSK_WITH_AES_128_CCM_8				0xC0A8

int connect_socket(sa_family_t family, struct sockaddr* addr, const char *server, int *sock);