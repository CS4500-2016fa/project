#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/module.h>
asmlinkage int sys_print_other (int process)
{
	struct pid *pid_struct;
	struct task_struct *task;
	struct task_struct *parent;
	pid_struct = find_get_pid(process);
	task = pid_task(pid_struct, PIDTYPE_PID);
	parent = task->parent;
	printk("%d", process);
	printk("\n%s [%d]\nruntime:%d, parent:%d\nvruntime:%llu", task->comm, task->pid,
			task->real_start_time.tv_sec, parent->pid, task->se.vruntime);
	for(task=current;task!=&init_task;task=task->parent)
	{
		printk("%s [%d]\n",task->comm , task->pid);
	}
	return 1;
}
