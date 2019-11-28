# ChetOS
This project is based on a UNIX based operating system where we implement many key OS features. The expected features are:

## System calls
develop the interface between kernel and user space. The system provides system calls such that the userland proceses can interact with the kernel. This was developed by using software interrupts.

## Physical memory management
The kernel has a memory system in which it can reserve and free memory pages of 4kb continuous memory. This feature was implemented as a simply linked list.

This feature requires the following syscalls:
   - Reserve memory for the calling process
   - Freememory for the calling process
   
## Processes, context switching and scheduling. 
The system handles a pre-emptive multi tasking environment where a variable ammount of processes live. This was implemented via software interrupts and a doubly linked list of active processes.

## IPCs
A system of blocking message sending between processes was implemented where a fixed ammount of bytes were sent. This was implemented using a common identifier between processes which was a defined string. For this to work, mutexes were implemented which lock and unlick the identifiers.

## Drivers
Keyboard and video drivers were implemented to better visualize and interact with the OS

## Userland applications

The following userland applications were developed for demonstration purpouses

### sh 
A userland shell which allows for the execution of the rest of the userland programs.

### ps 
Shows a list of processes with their PID, name, state, forground, reserved memory and other relevant data

### prodcons
shows a resolution to the producer consumer problem with a bounded buffer. The ammount of producers and consumers can be adjusted at runtime.

### help
Shows a list of the available commands
