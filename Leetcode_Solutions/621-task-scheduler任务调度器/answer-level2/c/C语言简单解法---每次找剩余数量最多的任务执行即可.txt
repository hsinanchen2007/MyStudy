C语言比较简单的方法
```
#define MAX_TASK_KIND   26

int g_allTaskInfo[MAX_TASK_KIND] = { 0 };
int g_allTaskWaitTime[MAX_TASK_KIND] = { 0 };
int g_allTaskNum = 0;
int g_resultCnt  = 0;

void RefreshWaitTime(int isExec, int curExecTask)
{
    for (int i = 0; i < MAX_TASK_KIND; i++) {
        if (isExec && (i == curExecTask)) {
            continue;
        }

        if (g_allTaskWaitTime[i] != 0) {
            g_allTaskWaitTime[i]--;
        }
    }
}

void HandleMain(int n)
{
    int i;
    int isExec = 0;
    int maxTaskNum = 0;
    int maxTaskIndex = 0;
    
    for (i = 0; i < MAX_TASK_KIND; i++) {
        if ((g_allTaskInfo[i] > maxTaskNum) && (g_allTaskWaitTime[i] == 0)) {
            maxTaskNum = g_allTaskInfo[i];
            maxTaskIndex = i;
            isExec = 1;
        }
    }

    if (isExec) {
        g_allTaskInfo[maxTaskIndex]--;
        g_allTaskWaitTime[maxTaskIndex] = n;
        g_allTaskNum--;
    }

    RefreshWaitTime(isExec, maxTaskIndex);
}

int leastInterval(char* tasks, int tasksSize, int n) 
{
    memset(g_allTaskInfo, 0, sizeof(int) * MAX_TASK_KIND);
    memset(g_allTaskWaitTime, 0, sizeof(int) * MAX_TASK_KIND);
    g_allTaskNum = tasksSize;
    g_resultCnt = 0;

    for (int i = 0; i < tasksSize; i++) {
        g_allTaskInfo[tasks[i] - 'A']++;
    }

    while (g_allTaskNum != 0) {
        HandleMain(n);
        g_resultCnt++;
    }

    return g_resultCnt;
}
```
