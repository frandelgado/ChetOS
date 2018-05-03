//
// Created by juangod on 15/04/18.
//

#ifndef TP2_TEMPORARY_PROCESS_H
#define TP2_TEMPORARY_PROCESS_H

#include <stdint.h>
typedef uint16_t pid_t;

typedef struct process_context_CDT * process_context;
struct process_context_CDT {
    uint64_t stackBasePointer;
    // registros etc
};

typedef struct process_t_CDT * process_t;
struct process_t_CDT {
    pid_t pid;
    char sleeps;
    process_context context;
};

void freeProcessMemory(process_t process);

#endif //TP2_TEMPORARY_PROCESS_H