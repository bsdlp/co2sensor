#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

int main()
{
	stdio_init_all();

	if (cyw43_arch_init_with_country(CYW43_COUNTRY_UK))
	{
		printf("failed to initialize\n");
		return 1;
	}
	printf("initialized\n");

	cyw43_arch_enable_sta_mode();
	printf("Connecting to WiFi...\n");
	if (cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASSWORD, CYW43_AUTH_WPA2_AES_PSK, 30000))
	{
		printf("failed to connect.\n");
		exit(1);
	}
	else
	{
		printf("Connected.\n");
	}

	cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
	while (true)
	{
	}
}