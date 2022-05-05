#include "blink.h"
#include "dual_core.h"
#include "lcd.h"
#include "priority.h"
#include "wifi.h"

void app_main(void)
{
    blink();
    dual_core();
    lcd();
    priority();
    wifi();
}
