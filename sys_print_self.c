#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/module.h>
asmlinkage int sys_print_self (void)
{
	struct task_struct *task;
	struct task_struct *parent;
	task = current;
	parent = task->parent;
	printk("\n%s [%d]\nruntime:%d, parent:%d\nvruntime:%llu", task->comm, task->pid,
			task->real_start_time.tv_sec, parent->pid, task->se.vruntime);
	for(task=current;task!=&init_task;task=task->parent)
	{
		printk("%s [%d]\n",task->comm , task->pid);
	}
	return 1;
}
