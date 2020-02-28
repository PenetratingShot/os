/*
    terminal.c
    Copyright Shreyas Lad (PenetratingShot) 2020

    Terminal
*/

#include <sys/knl/terminal.h>

uint32_t largestUseableMem = 0;

void userInput(char* input) {
  if (strcmp(input, "halt") == 0) {
    kprint("Halting CPU");
    asm volatile("hlt");
  } else if (strcmp(input, "time") == 0) {
    formatTime();

    kprint(format);
  } else if (strcmp(input, "clear") == 0) {
    clear();

    formatTime();

    printf("flameOS\nIt is %d.\n", second);
  } else if (strcmp(input, "testmem") == 0) {
    uint64_t* address = malloc(64);
    printf("Address 1: %x\n", address);

    address = malloc(64);
    printf("Address 2: %x\n", address);
  } else if (strcmp(input, "neofetch") == 0) {
    neofetch(largestUseableMem);
  } else if (strcmp(input, "uptime") == 0) {
    calculateUptime();
  } else if (strcmp(input, "drives") == 0) {
    drive_scan();
    if (hdd.mp == 0 || hdd.mp48 == 0) {
      kprint("Primary IDE, Master Drive (Drive 1): Online\n");
    } else {
      kprint("Primary IDE, Master Drive (Drive 1): Offline\n");
    }
    if (hdd.ms == 0 || hdd.ms48 == 0) {
      kprint("Primary IDE, Slave Drive (Drive 2): Online\n");
    } else {
      kprint("Primary IDE, Slave Drive (Drive 2): Offline\n");
    }
    if (hdd.sp == 0 || hdd.sp48 == 0) {
      kprint("Secondary IDE, Master Drive (Drive 3): Online\n");
    } else {
      kprint("Secondary IDE, Master Drive (Drive 3): Offline\n");
    }
    if (hdd.ss == 0 || hdd.ss48 == 0) {
      kprint("Secondary IDE, Slave Drive (Drive 4): Online\n");
    } else {
      kprint("Secondary IDE, Slave Drive (Drive 4): Offline\n");
    }
  } else if (strcmp(input, "read") == 0) {
    read_disk(0);
  } else if (strcmp(input, "driveTest") == 0) {
    writeIn[0] = 0x1111;
    write(0, 0);
  } else {
    if (strcmp(input, "") == 0) {

    } else {
      kprint("Unrecognized command: ");
      kprint(input);
    }
  }
  kprint("\nuser@flameOS # ");
}