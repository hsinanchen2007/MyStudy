思路：
    原理比较简单，贪心算法。
    （1）统计所有类类型任务的剩余次数，并按降序排序；
    （2）每一轮都按任务剩余次数大小优先选择剩余次数多的，并且每一轮都选择尽可能多的任务，但最多不超过n+1。在每一轮选择任务时，每种任务最多每选中一次。
    （3）每一轮选择完后，对任务剩余次数重新按将序排序。如果剩余次数最大值taskCnt[0]为0，说明所有任务都以调度完，结束调度；否则调度次数times++，进入下一轮调度。
    （4）除了最后一次调度外，前面每次调度的时间都是n+1单位的时间（如果没有n+1个任务，就会用“待命”时间填充）；最后一论调度的时间是实际任务的个数，可以小于n+1。

代码：
#define MAXTASK     26

int Comp(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

int leastInterval(char* tasks, int tasksSize, int n){
    int i;
    int count;
    int times = 0;
    int taskCnt[MAXTASK] = {0};

    for (i = 0; i < tasksSize; i++) {
        taskCnt[tasks[i] - 'A']++;
    }

    qsort(taskCnt, MAXTASK, sizeof(int), Comp);
    
    while (taskCnt[0] > 0) {
        count = 0;
        for (i = 0; i < MAXTASK; i++) {
            if (taskCnt[i] == 0) {
                break;
            }
            taskCnt[i]--;
            count++;
            if (count == n + 1) {
                break;
            }
        }
        qsort(taskCnt, MAXTASK, sizeof(int), Comp);
        if (taskCnt[0] == 0) {
            break;
        }
        times++;
    }

    return times * (n + 1) + count;
}
