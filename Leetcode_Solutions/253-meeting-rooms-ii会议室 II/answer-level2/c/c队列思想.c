### 解题思路
先已会议开始时间排序。
建立会议室队列
遍历会议， 对每次会议，开始时间即当前时间，遍历会议室，比较会议室时间和会议开始时间，对会议室结束时间小于当前时间，则释放会议室。
最后新增会议室，入对。
比较当前会议室个数和最大个数。得到最大值。

### 代码

```c

typedef struct tagRoom {
    int start;
    int end;
    struct tagRoom *next;
} Room_S;

int cmp( const void *a, const void *b)
{
    int *t1 = *(int**)a;
    int *t2 = *(int**)b;
    // printf("a: %d %d, b: %d %d\n", t1[0],t1[1],  t2[0], t2[1]);
    return t1[0] - t2[0];
}



/**
 * https://leetcode-cn.com/problems/meeting-rooms-ii/
 */
int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize)
{
    int maxCnt = 0;
    if (intervalsSize == 0) {
        return 0;
    }
    Room_S *head = NULL;
    qsort(intervals, intervalsSize, sizeof(int(*)[2]), cmp);
    for (int i = 0; i < intervalsSize; i++) {
        Room_S *p = head;
        Room_S *pre = NULL;
        int cnt = 0;
        while (p) { //遍历队列, 由于已排序，开始时间不用再比较
            // printf("in que end %d, i %d start %d", p->end, i, intervals[i][0]);
            if (p->end <= intervals[i][0]) { // 会议室释放
                Room_S *tmp = p->next;
                if (pre) {
                    pre->next = p->next;
                } else {
                    head = p->next;
                }
                free(p);
                p = tmp;
            } else {  // 会议冲突, 遍历下一个
                pre = p;
                p = p->next;
                cnt++;
            }
        }
        // 占用会议室
        p = (Room_S *)malloc(sizeof(Room_S));
        if (p == NULL) {
            return 0;
        }
        p->start = intervals[i][0];
        p->end = intervals[i][1];
        p->next = NULL;
        if (pre) {
            pre->next = p;
        } else {
            head = p;
        }
        cnt++;
        maxCnt = maxCnt > cnt ? maxCnt:cnt;
    }
    Room_S  *p = head;
    while(p) {
        Room_S *tmp = p->next;
        free(p);
        p = tmp;
    }
    return maxCnt;
}
```