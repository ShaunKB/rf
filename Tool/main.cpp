#include "rfnt.h"
#include "scanner.h"
#include <thread>

void Main(void)
{

  DWORD dw_min = 0x400000;
  DWORD dw_max = 0x7FFFFF;

  while (FindWindow("Rumble Fighter", "Rumble Fighter") == NULL)
    std::this_thread::sleep_for(std::chrono::milliseconds(2500));

  DWORD nanmu_address = scanner::find_pattern(dw_min, dw_max, "C6 86 ? ? ? ? 01 53 8B CE E8 ? ? ? ? 8B");
  Hack* nanmu = new Hack(nanmu_address, "C6 86 A5", "C6 86 A4");

  //DWORD godmode_address = scanner::find_pattern(dw_min, dw_max, "C6 86 ? ? ? ? 01 53 8B CE E8 ? ? ? ? 8B");
  //Hack* godmode = new Hack(godmode_address, "66 89 59", "66 89 54");

  DWORD air_glide_address = scanner::find_pattern(dw_min, dw_max, "C0 00 00 A0 40 0A D7 23");
  DWORD air_suspend_address = air_glide_address - 0x1;
  Hack *air_suspension = new Hack(air_suspend_address, "90 90 90", "80 C0 00");

  MessageBoxA(NULL, "RFNT Ready For Use!\n  1. Use F1 to reset Nanmu.\n  2. Use F2 to enable suspend fall.", "RFNT", 0);

  while (true) {
    if (GetAsyncKeyState(VK_F1) & 1) {
      nanmu->toggle();
      // # waits for iteration over character state
      std::this_thread::sleep_for(std::chrono::milliseconds(250));
      // # flip bytes back to avoid detection, nanmu counter reset to 1
      nanmu->toggle();
    }
    if (GetAsyncKeyState(VK_F2) & 1) {
      air_suspension->toggle();
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
  }
}
