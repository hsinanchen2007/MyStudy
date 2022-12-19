#define MAX_CHAR_NUM 26
int g_count[MAX_CHAR_NUM];
int Mycomp(const void *a, const void *b) 
{
    return *(int *)b - *(int *)a;
}

int Proc(int n, int sum) 
{
    qsort(g_count, MAX_CHAR_NUM, sizeof(int), Mycomp);
    int slotNum = g_count[0] - 1; // 中间空隙数
    int slotTime = slotNum * n; // 中间空隙时长
    if (sum - g_count[0] > slotTime) { // 最大任务的中间时间全部可以塞满
        return sum;
    }
    int shortTime = g_count[0] + slotTime; // 任务0的最少时间
    for (int i = 1; i < MAX_CHAR_NUM; i++) {
        if (g_count[i] > slotNum) { // 理论上只可能大1       
            shortTime++; // 还剩一个加在后面即可
        } else {
            return shortTime;
        }
    }
    return shortTime;
}

int leastInterval(char* tasks, int tasksSize, int n){
    if (tasksSize == 0) {
        return 0;
    }

    memset(g_count, 0, sizeof(g_count));
    int sum = 0;
    for (int i = 0; i < tasksSize; i++) {
        g_count[tasks[i] - 'A']++;
        sum++;
    }
    return Proc(n, sum);
}
![QQ图片20191215100135.png](https://pic.leetcode-cn.com/ff9ead0087f1055856a845e00a42b2843c25e20db03ee290509e25a232f8e277-QQ%E5%9B%BE%E7%89%8720191215100135.png)
