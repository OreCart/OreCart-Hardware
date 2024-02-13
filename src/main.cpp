#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#include "common/van_info.h"
#include "common/location.h"

#include "modules/net_module/net_module.h"
#include "modules/tracking_module/tracking_module.h"

#define LED0_NODE DT_ALIAS(led0)
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

#define SLEEP_TIME_MS 2000

VanInfo van_info;

int main() {
	OC_LOG_INFO("Welcome to the OreCart Hardware Project!");
    int ret;

	net_module_init();

    if (!gpio_is_ready_dt(&led)) {
        return 0;
    }

    ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return 0;
	}

	struct VanInfo van_info = {
		.van_id = 1
	};

	// Default location.
	struct Location location = {.lat=213.12, .lon=20.123};

	while (1) {
		location_gnss_high_accuracy_get(void)
		forward_van_location(van_info, location, 100);
		k_sleep(K_SECONDS(1));
	}

	while (1) {
		k_sleep(K_SECONDS(15));
	}

	return 0;
}
