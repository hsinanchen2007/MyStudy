### 解题思路
要有耐心：按照调度次数来循环，注意最后一次。

### 代码

```c
int Compare (const void *a, const void *b) 
{
    return *(int*)b - *(int*)a;
}
int leastInterval(char* tasks, int tasksSize, int n){
    int minTime = 0;
    int taskCount[26] = {0};
    int taskNum = 0;
    int busyTime = n+1;
    int schedu = 0;
    int sc = 0;
    if (tasksSize == 1) {
        return 1;
    }
    if (n == 0) {
        return tasksSize;
    }

    for (int i = 0; i < tasksSize; i++) {
        if(taskCount[tasks[i] - 'A'] == 0) {
            taskNum++;
        }
        taskCount[tasks[i] - 'A']++;
    }

    qsort(taskCount, 26, sizeof(int), Compare);

    while (tasksSize) {
        //按照每轮的冷却时间来计算
        busyTime = n+1;
        sc = 0;
        for (int i = 0; i < taskNum; i++) {
            if(taskCount[i] > 0) {
                taskCount[i]--;
                tasksSize--;
                busyTime--;
                sc++;
            }                      
            if (busyTime == 0) {
                schedu++;
                break;
            }
        }      
        if (busyTime) {
            schedu++;
        }
       // printf("left %d, sched %d\n",tasksSize, schedu);               
        qsort(taskCount, 26, sizeof(int), Compare);
    }
    minTime = (schedu-1) * (n+1) + sc;
    return minTime;
}
```