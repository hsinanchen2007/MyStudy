### 解题思路
一个会议室一个会议室的去安排会议。

### 代码

```c
int Compare(const void *a, const void *b)
{
    int **pa = (int**)a;
    int **pb = (int**)b;
    return pa[0][0] - pb[0][0];
}
int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize){
    int rooms = 0;
    int *meetings = NULL;
    int meetingHaveRoom = 0;
    int curMeet[2] = {0};
    if(intervalsSize < 2) {
        return intervalsSize;
    }
    qsort(intervals, intervalsSize, sizeof(intervals[0]), Compare);
    meetings = (int*)calloc(intervalsSize, sizeof(int));

    while (meetingHaveRoom < intervalsSize) {
        // 为每间会议室安排会议
        int first = 0;
        rooms++;
        for (int i = 0; i < intervalsSize; i++) {
            if (meetings[i] == 0) {
                if (first == 0){// 记录当前会议的开始和结束时间
                    first = 1;
                    curMeet[0] = intervals[i][0];
                    curMeet[1] = intervals[i][1];
                    meetings[i] = 1;
                    meetingHaveRoom++;                    
                } else {
                    // 当前会议结束时间小于下一个会议开始时间
                    if(curMeet[1] <= intervals[i][0]) {
                        curMeet[0] = intervals[i][0];
                        curMeet[1] = intervals[i][1];
                        meetings[i] = 1;
                        meetingHaveRoom++;
                    }
                } 
            }
        }
    }
    free(meetings);
    return rooms;
}
```