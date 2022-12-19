### 解题思路
循环队列
从队头到队尾
从队尾到队头
### 代码

```c
#define MIN(a, b) ((a < b) ? a : b)
#define PRINTF // printf
int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination){
    int rightDis = 0;
    int leftDis = 0;
    int curPos = start;
    if ((start < 0) || (start >= distanceSize)) {
        return 0;
    }
    if ((destination < 0) || (destination >= distanceSize)) {
        return 0;
    }
    while (curPos != destination) {
        int nextPos = ((curPos + 1) % distanceSize);
        rightDis += distance[curPos];
        PRINTF("right:%d %d\n", curPos, distance[curPos]);
        curPos = nextPos;
    }
    curPos = destination;
    while (curPos != start) {
        int nextPos = ((curPos + 1) % distanceSize);
        leftDis += distance[curPos];
        PRINTF("left:%d %d\n", curPos, distance[curPos]);
        curPos = nextPos;
    }
    return MIN(rightDis, leftDis);
}
```