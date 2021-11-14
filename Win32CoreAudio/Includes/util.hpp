#pragma once

#include <cstdio>

#define LOGD(format, ...)	std::printf(format "\n", __VA_ARGS__)
#define LOGE(format, ...)	std::printf("Error: " format "\n", __VA_ARGS__)