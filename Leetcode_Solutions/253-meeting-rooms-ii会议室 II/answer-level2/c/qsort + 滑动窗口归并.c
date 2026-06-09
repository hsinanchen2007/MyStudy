### 解题思路
此处撰写解题思路
执行用时 :16 ms, 在所有 C 提交中击败了95.08%的用户
内存消耗 :7 MB, 在所有 C 提交中击败了100.00%的用户
### 代码

```c
/*
1,先排序,涉及这种元素大小影响结果的,先qsort
2.滑动窗口,把能归并的元素,放一起
3.计算个数
*/
#define MAX 10000

int Com(const void *a, const void *b)
{
    int *a1 = *(int **)a;
    int *b1 = *(int **)b;
    if (a1[0] == b1[0]) {
        return a1[1] > b1[1];
    }
    return a1[0] > b1[0];
}

int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize)
{
    qsort(intervals, intervalsSize, sizeof(int *), Com);
    bool used[MAX] = {0};
    int buf[2];
    int num = 0;
    for (int i = 0; i < intervalsSize; i++) {
        if (used[i]) {
            continue;
        }
        buf[0] = intervals[i][0];
        buf[1] = intervals[i][1];
        used[i] = true;
        int cnt = 0;
        //printf("%d: vals[%d]=[%d %d], size=%d, used=%d\n", __LINE__, i, buf[0], buf[1], intervalsSize, used[i]);
        for (int j = 0; j < intervalsSize; j++) {
            if (used[j]) {
                continue;
            }
            //printf("%d: vals[%d]=[%d %d], cnt=%d, num=%d\n", __LINE__, i, buf[0], buf[1], cnt, num);
            if (buf[1] <= intervals[j][0]) {
                buf[1] = intervals[j][1];
                used[j] = true;
                cnt++;
            }
        }
        num += cnt;
        //printf("%d: vals[%d]=[%d %d], cnt=%d, num=%d\n", __LINE__, i, intervals[i][0], intervals[i][1], cnt, num);

    }
    return intervalsSize - num;
}

```