### 解题思路
1、首先是将任务进行统计，因为是字母，因此，使用26长度的数组保存
2、统计的同时计算最大的字母（提高后续排序的效率）
3、遍历，每次遍历的时候保证遍历的间隔是N（如果不足N需要补齐，这里特别注意间隔需要使用N+1-X，我开始没有+1，计算的总是不对）

### 代码

```c
#define MAX_TASK_NUM 26
#define ISUPPER(c) (((c) >= 'A') && ((c) <= 'Z'))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef struct CalCount {
    short val;
    short num;
} CALCOUNT;

int CompareNum(const void *a, const void *b)
{
    CALCOUNT *old = (CALCOUNT *)a;
    CALCOUNT *input = (CALCOUNT *)b;

    if (input->num > old->num) {
        return 1;
    }
    return -1;
}


int leastInterval(char *tasks, int tasksSize, int n)
{
    CALCOUNT taskNum[MAX_TASK_NUM + 1];
    int count;
    int maxVal;
    int staticNum;
    char last;
    if (tasksSize == 0) {
        return 0;
    }

    if (n == 0) {
        return tasksSize;
    }

    memset(taskNum, 0x0, sizeof(taskNum));
    maxVal = 0;
    for (int index = 0; index < tasksSize; index++) {
        if (!ISUPPER(tasks[index])) {
            continue;
        }
        taskNum[tasks[index] - 'A'].num++;
        maxVal = MAX(maxVal, tasks[index] - 'A');
    }
    for (int index = 0; index < MAX_TASK_NUM; index++) {
        taskNum[index].val = index;
    }
    qsort(taskNum, (maxVal + 1), sizeof(taskNum[0]), CompareNum);

    count = 0;
    last = -1;
    staticNum = 0;
    for (int index = 0; index < tasksSize; ) {
        staticNum = 0;
        for (int task = 0; task <= maxVal; task++) {
            if (taskNum[task].num <= 0) {
                continue;
            }
            taskNum[task].num--;
            staticNum++;
            if (staticNum == n + 1)
            {
                break;
            }
        }

        index += staticNum;
        if (index < tasksSize)
        {
            if (staticNum < n + 1)
            {
                count += (n + 1 - staticNum);
            }
        }

        qsort(taskNum, (maxVal + 1), sizeof(taskNum[0]), CompareNum);        
    }

    //printf("\r\n tasksSize=%d, count=%d", tasksSize, count);
    return (tasksSize + count);
}
```