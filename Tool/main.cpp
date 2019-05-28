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

  //DWORD counter_address = scanner::find_pattern(dw_min, dw_max, "8D 4C 8B 04 89 4D 08") + 0xA;
  //Hack *speed_counter = new Hack(counter_address, "0F 85", "0F 84");

  DWORD room_crash_address = scanner::find_pattern(dw_min, dw_max, "88 47 07 C6 47 17 00 BA");
  Hack *room_crash = new Hack(room_crash_address, "88 47 03", "88 47 07");

  MessageBoxA(NULL, "RFNT Ready For Use!\n  "
                    "1. Use F1 to reset Nanmu.\n  "
                    "2. Use F2 to enable suspend fall.\n  "
                    // "3. Use F3 to spam counter briefly.\n  "
                    "3. Use F3 to trigger a room crash.", "RFNT", 0);

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
    //if (GetAsyncKeyState(VK_F3) & 1) {
    //  speed_counter->toggle();
    //  // # give user window for counter spamming
    //  std::this_thread::sleep_for(std::chrono::milliseconds(500));
    //  // # flip bytes back to avoid detection
    //  speed_counter->toggle();
    //}
    if (GetAsyncKeyState(VK_F3) & 1) {
      room_crash->toggle();
      // # wait for user to get hit
      std::this_thread::sleep_for(std::chrono::milliseconds(250));
      // # flip bytes back to avoid detection
      room_crash->toggle();
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
  }
}
