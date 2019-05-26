#include "rfnt.h"
#include "scanner.h"
#include <thread>

void Main(void)
{

  DWORD dw_min = 0x400000;
  DWORD dw_max = 0x7FFFFF;

  while (FindWindow("Rumble Fighter", "Rumble Fighter") == NULL)
    Sleep(2500);

  DWORD nanmu_address = scanner::find_pattern(dw_min, dw_max, "C6 86 ? ? ? ? 01 53 8B CE E8 ? ? ? ? 8B");
  Hack* nanmu = new Hack(nanmu_address, "C6 86 A5", "C6 86 A4");

  //DWORD godmode_address = scanner::find_pattern(dw_min, dw_max, "C6 86 ? ? ? ? 01 53 8B CE E8 ? ? ? ? 8B");
  //Hack* godmode = new Hack(godmode_address, "66 89 59", "66 89 54");

  MessageBoxA(NULL, "RFNT Ready For Use!\n  1. Use F1 to reset Nanmu.\n  2. Use F2 to enable godmode.", "RFNT", 0);

  while (true) {
    if (GetAsyncKeyState(VK_F1) & 1) {
      nanmu->toggle();
      std::this_thread::sleep_for(std::chrono::milliseconds(250));
      nanmu->toggle();
    }
    /*if (GetAsyncKeyState(VK_F2) & 1) {
      godmode->toggle();
    }*/
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
  }
}
