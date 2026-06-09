算法的关键： 相同的任务需要冷却，如果不相同则不需要。选择n+1个不同种类的任务进行调度。

在存在多个相同的任务的时候，如果希望不停顿，那么最好的方式是刚好插入n+1个其他的任务，然后从最多的任务中再选一个重新按照n+1的策略进行调度。当最后每种种类的任务都只剩下1个后，则不需要停顿，一次性处理完成。

```
#define TASKCLASS       26

int CheckParam(char* tasks, int tasksSize, int n)
{
    if (tasks == NULL || tasksSize <= 0 || n < 0) {
        return -1;
    }

    return 0;
}

int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}
int leastInterval(char* tasks, int tasksSize, int n)
{
    if (CheckParam(tasks, tasksSize, n)) {
        return 0;
    }
    
    int taskStat[TASKCLASS] = {0};
    for (int i = 0; i < tasksSize; ++i) {
        taskStat[tasks[i] - 'A']++;
    }

    qsort(taskStat, TASKCLASS, sizeof(int), cmp);

    int i = tasksSize;
    int times = 0;
    while (i > 0) {
        if (taskStat[0] > 1) { //存在多个的情况下，按照n+1的规格进行安排
            int j = 0;
            while (j < n + 1) {
                if (j < TASKCLASS && taskStat[j] > 0) { //安排n + 1个任务
                    taskStat[j]--;
                    i--;
                }
                j++;
                times++;
            }
        } else { //只有一个的情况下，所有的任务安排一次即可，不需要按照n+1的处理
            times += i;
            i = 0;
            break;
        }

        qsort(taskStat, TASKCLASS, sizeof(int), cmp);
    }

    return times;
}
```
