### 解题思路
1) table数组中存放对应的会议是否被安排。
2) 排序
3) 找到一个没有安排的会议，会议室个数rooms++，找以本会议会开始和结束为时间的最长递增会议，标记为已安排。
4) 循环3，直到找不到还没有被安排的会议。

### 代码

```c
int cmpfun(void* arg1, void* arg2)
{
    int *a = *(int**)arg1;
    int *b = *(int**)arg2;
    return a[0] - b[0];
}

int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize){
    if (intervalsSize == 0) {
        return 0;
    }
    int table[intervalsSize];
    int rooms = 0;
    int roomsEnd;
    for (int i = 0; i < intervalsSize; ++i) {
        table[i] = 0;
    }
    qsort(intervals, intervalsSize, sizeof(int) * 2, cmpfun);
    int find = 1;
    while (find) {
        find = 0;
        for (int i = 0; i < intervalsSize; ++i) {
            if (find) {
                if (table[i] == 0 && roomsEnd <= intervals[i][0]) {
                    table[i] = 1;
                    roomsEnd =  intervals[i][1];
                }
                continue;
            }
            if (table[i] == 0) {
                find = 1;
                table[i] = 1;
                roomsEnd = intervals[i][1];
                ++rooms;
            }
        }
    }
    return rooms;
}
```