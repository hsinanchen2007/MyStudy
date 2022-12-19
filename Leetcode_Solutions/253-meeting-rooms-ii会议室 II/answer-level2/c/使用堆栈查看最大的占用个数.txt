### 解题思路
本体参考解题的答案思路，主要为：
1、首先需要使用qsort进行排序（先使用开始时间，再使用结束时间）
2、然后按照顺序压栈
3、每次加入栈前先将本次加入元素的开始时间跟栈中元素的结束时间比较，如果大于结束时间，将以前元素从栈中取出
4、然后插入元素
5、栈中元素的最大值，就是需要的最大会议室个数

### 代码

```c
#define DEFAULT_COL_SIZE 2
#define MAX(a, b)   ((a) > (b) ? (a) : (b))

typedef struct MeetingTime {
    int begin;
    int end;
} MEETINGTIME;

int Compare(const void *a, const void *b)
{
    int **old = (int **)a;
    int **input = (int **)b;

    if (old[0][0] > input[0][0]) {
        return 1;
    }

    if (old[0][0] < input[0][0]) {
        return 0;
    }
    return (old[0][1] - input[0][1]);
}

int minMeetingRooms(int **intervals, int intervalsSize, int *intervalsColSize)
{
    int maxCount;
    int maxNum = intervalsSize + 2;
    int insertNum = 0;
    MEETINGTIME *meetingTime = NULL;

    if (intervalsSize == 0) {
        return 0;
    }

    qsort(intervals, intervalsSize, sizeof(intervals[0]), Compare);

    meetingTime = (MEETINGTIME *)malloc(maxNum * sizeof(MEETINGTIME));
    if (meetingTime == NULL) {
        return 0;
    }
    memset(meetingTime, 0x0, maxNum * sizeof(MEETINGTIME));
    meetingTime[0].begin = intervals[0][0];
    meetingTime[0].end = intervals[0][1];
    insertNum++;
    maxCount = 1;

    for (int index = 1; index < intervalsSize; index++) {
        int curNum = insertNum;
        if (intervalsColSize[index] != DEFAULT_COL_SIZE) {
            printf("\r\n error col size, index= %d size=%d", index, intervalsColSize[index]);
        }

        /* 查看当前的会议室，哪些会议室已经可以退出 */
        for (int col = curNum - 1; col >= 0; col--) {
            if (intervals[index][0] >= meetingTime[col].end) {
                memmove(&meetingTime[col], &meetingTime[col + 1], (curNum - 1 - col + 1) * sizeof(MEETINGTIME));
                insertNum--;
            }
        }

        meetingTime[insertNum].begin = intervals[index][0];
        meetingTime[insertNum].end = intervals[index][1];
        insertNum++;
        maxCount = MAX(maxCount, insertNum);
    }

    free(meetingTime);
    return maxCount;
}
```