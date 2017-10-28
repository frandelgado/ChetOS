section .text

GLOBAL getTimeRTC

getTimeRTC:
  push rbp
  mov rbp, rsp

  mov al,0x0B ; RTC Status Register B
  out 70h,al
  in al, 71h
  or al, 0x04 ; Second bit = 1
  out 71h, al ; Overwrite config

  mov rax, rdi
  out 70h,al

  in al,71h
  movzx rax, al

  mov rsp, rbp
  pop rbp
  ret
