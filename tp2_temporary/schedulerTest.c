#include <stdio.h>
#include "process.h"
#include "scheduler.h"
#include "testLib.h"

//
// Created by juangod on 18/04/18.
//
process_t p1;
process_t p2;
process_t p3;
process_t p4;
process_t p5;
process_t p6;
process_t p10;
process_t t1;

void given3Processes(){
    p1 = malloc(sizeof(struct process_t_CDT));
    if(p1==NULL) perror("Malloc returned NULL.");
    p1->context = malloc(sizeof(struct process_context_CDT));
    if(p1->context==NULL) perror("Malloc returned NULL.");
    p2 = malloc(sizeof(struct process_t_CDT));
    if(p2==NULL) perror("Malloc returned NULL.");
    p2->context = malloc(sizeof(struct process_context_CDT));
    if(p2->context==NULL) perror("Malloc returned NULL.");
    p3 = malloc(sizeof(struct process_t_CDT));
    if(p3==NULL) perror("Malloc returned NULL.");
    p3->context = malloc(sizeof(struct process_context_CDT));
    if(p3->context==NULL) perror("Malloc returned NULL.");

    p1->pid = 2;
    p2->pid = 2;
    p3->pid = 2;
    p1->sleeps=0;
    p2->sleeps=0;
    p3->sleeps=0;
}

void given3OtherProcesses(){
    p4 = malloc(sizeof(struct process_t_CDT));
    if(p4==NULL) perror("Malloc returned NULL.");
    p4->context = malloc(sizeof(struct process_context_CDT));
    if(p4->context==NULL) perror("Malloc returned NULL.");
    p5 = malloc(sizeof(struct process_t_CDT));
    if(p5==NULL) perror("Malloc returned NULL.");
    p5->context = malloc(sizeof(struct process_context_CDT));
    if(p5->context==NULL) perror("Malloc returned NULL.");
    p6 = malloc(sizeof(struct process_t_CDT));
    if(p6==NULL) perror("Malloc returned NULL.");
    p6->context = malloc(sizeof(struct process_context_CDT));
    if(p6->context==NULL) perror("Malloc returned NULL.");

    p4->pid = 2;
    p5->pid = 2;
    p6->pid = 2;
    p4->sleeps=0;
    p5->sleeps=0;
    p6->sleeps=0;
}


void whenQueueing3Processes() {
    queueProcess(p1);
    queueProcess(p2);
    queueProcess(p3);
}

void whenQueueing3OtherProcesses() {
    queueProcess(p4);
    queueProcess(p5);
    queueProcess(p6);
}

void thenNNotNullProcessesAreReceived(int n){
    char okFlag=1;
    int i;
    for(i=0;i<n;i++) {
        t1 = getNextProcess();
        if (t1 == NULL)
            okFlag = 0;
    }

    if(okFlag)
        ok();
    else
        perror("Polled NULL process when non-null expected.");
}

void thenQueueIsEmpty(){
    if(getAmountOfProcesses()!=0)
        perror("Queue not empty when expected to be empty.");
    else
        ok();
}

void thenQueueIsNotEmpty(){
    if(getAmountOfProcesses()==0)
        perror("Queue is empty when expected to be not empty.");
    else
        ok();
}

void whenSleepingProcess10(){
    sleepProcess(10);
}

void thenNextProcessHasCertainPID(pid_t pid){
    t1 = getNextProcess();
    if(t1->pid != pid)
        printf("Expected PID:%d, Received:%d \n",pid,t1->pid);
    else
        ok();
}

void givenAProcessWithPID10(){
    p10 = malloc(sizeof(struct process_t_CDT));
    if(p10==NULL) perror("Malloc returned NULL.");
    p10->context = malloc(sizeof(struct process_context_CDT));
    if(p10->context==NULL) perror("Malloc returned NULL.");
    p10->pid = 10;
    p10->sleeps=0;
}

void whenQueueingProcessWithPID10(){
    queueProcess(p10);
}

void whenDestroyingQueue(){
    destroyProcessQueue();
}

void add3ProcessesTest(){
    printf("Testing 3 Processes Test\n");

    given3Processes();
    whenQueueing3Processes();
    thenNNotNullProcessesAreReceived(3);

    thenQueueIsEmpty();

    freeProcessMemory(p1);
    freeProcessMemory(p2);
    freeProcessMemory(p3);
}

void checkSleepTest(){
    printf("Testing Sleep Test\n");

    given3Processes();
    givenAProcessWithPID10();
    whenQueueingProcessWithPID10(); //p10 is queued first
    whenQueueing3Processes();
    whenSleepingProcess10();
    thenNextProcessHasCertainPID(2); // Default PID is 2, if it is 10 then the sleeping process was incorrectly returned
    thenNNotNullProcessesAreReceived(2);
    thenQueueIsNotEmpty();
    freeProcessMemory(p1);
    freeProcessMemory(p2);
    freeProcessMemory(p3);
    destroyProcessQueue();
}

void queueDestructionTest(){
    printf("Testing Queue Destruction Test\n");

    givenAProcessWithPID10();
    given3OtherProcesses();
    given3Processes();
    whenQueueing3OtherProcesses();
    whenQueueing3Processes();
    whenQueueingProcessWithPID10();
    whenDestroyingQueue();
    thenQueueIsEmpty();
}

void queue100processesThenDestroy(){
    int i = 0;
    process_t p;
    for (i=0;i<100;i++){
        queueProcess(calloc(1,sizeof(struct process_t_CDT)));
    }
    listProcesses();
    destroyProcessQueue();
    thenQueueIsEmpty();
}

void schedulerTestRun(){
    add3ProcessesTest();
    checkSleepTest();
    queueDestructionTest();
    //queue100processesThenDestroy();
}