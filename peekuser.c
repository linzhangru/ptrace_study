
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/user.h>   /* For constants ORIG_RAX etc */
#include <sys/reg.h>

int main()
{
    pid_t child;
    long orig_eax;
    struct user_regs_struct regs;
    struct user* user_space = (struct user*)0;
    
    child = fork();
    if(child == 0) {
	ptrace(PTRACE_TRACEME, 0, NULL, NULL);
	execl("/bin/ls", "ls", NULL);
    } else {
	wait(NULL);
	//long original_rax = ptrace(PTRACE_PEEKUSER, child, 8 * ORIG_RAX, NULL);
	long original_rax = ptrace(PTRACE_PEEKUSER, child, &user_space->regs.orig_rax, NULL);
	printf("The child made a system call %ld\n", original_rax);
	
	//ptrace(PTRACE_GETREGS, child, NULL, &regs);
	//printf("The child made a system call %lld\n", regs.orig_rax);
	
	ptrace(PTRACE_CONT, child, NULL, NULL);
    }

    free(user_space);
    
    return 0;
}
  
