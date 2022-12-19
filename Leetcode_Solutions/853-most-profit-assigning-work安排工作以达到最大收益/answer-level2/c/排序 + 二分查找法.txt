```

#define MAX_WORK_LENGTH    10001

struct Node {
    int d;
    int p;
};

struct Node g_list[MAX_WORK_LENGTH] = { { 0 } };

static int Compare(const void *arg1, const void *arg2)
{
    struct Node *node1 = (struct Node *)arg1;
    struct Node *node2 = (struct Node *)arg2;

    return (node1->d < node2->d) ? -1 : 1;    
}

static int FindIndex(int h, int target)
{
    int mid;
    int index = -1;
    int low = 0;
    int high = h;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (g_list[mid].d <= target) {
            index = mid;
            low = mid + 1;
        } else if (g_list[mid].d > target) {
            high = mid - 1;
        }
    }

    return index;
}

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize){
    int i;
    int index;
    int maxPro = 0;
    int totalPro = 0;
    int maxProList[MAX_WORK_LENGTH] = { 0 };

    memset(g_list, 0x0, MAX_WORK_LENGTH * sizeof(struct Node));
    for (i = 0; i < difficultySize; i++) {
         g_list[i].d = difficulty[i];
         g_list[i].p = profit[i];
    }

    //对工作排序;
    qsort(g_list, difficultySize, sizeof(struct Node), Compare);

    //记录每一个工作及之前所有工作中最大的收益;
    for (i = 0; i < difficultySize; i++) {
        if (maxPro < g_list[i].p) {
            maxPro = g_list[i].p;
            maxProList[i] = maxPro;
        } else {
            maxProList[i] = maxPro;
        }
    }

    for (i = 0; i < workerSize; i++) {
        //二分查找最后一个难度比工人能力低的工作索引;
        index = FindIndex(difficultySize - 1, worker[i]);
        if (index != -1) {
            totalPro += maxProList[index];
        }
    }

    return totalPro;
}
```
