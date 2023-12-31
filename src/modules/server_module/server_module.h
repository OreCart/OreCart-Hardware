#pragma once

#include <zephyr/kernel.h>

#include "../../common/location.h"
#include "../../common/van_info.h"

#define SERVER_HOST "orecart.local"
#define SERVER_PORT 8000

// #define SERVER_HOST "142.251.41.14"
// #define SERVER_PORT 80

#define PROTOCOL "HTTP/1.1"
#define TIMEOUT 5000

#define SEND_VAN_LOCATION_ROUTE "/location/"
// #define SEND_VAN_LOCATION_ROUTE "/"
#define SEND_OCCUPANCY_ROUTE "/states/ridership/"

extern struct k_sem is_modem_available;

// Lock semaphore until initialized.

void server_module_init();

// Send the current van location to the server.
// @location   -  a lat/long position of the van
// returns success boolean
bool server_send_van_location(VanInfo* vanInfo, struct Location location, uint64_t ts);

// Send the current ridership to the server.
// @ridership_delta   -   how many people got on/off the bus, negative for off and positive for on.
// returns success boolean
// bool server_send_ridership(VanInfo* vanInfo, int8_t ridership_delta, uint64_t ts);
