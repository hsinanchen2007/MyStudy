### 解题思路
这个题目我耗费的时间比较多，主要的坑有：
1、需要记录最短路径，开始对最短路径理解有误，题目有耽搁
2、遍历的时候对相同节点是否需要重复遍历，这个坑最多，主要有：
（1）允许遍历，有问题，导致搜寻场景太多，溢出
（2）不允许遍历，有问题，一些场景可能将最优解给遗漏
真实的做法是需要判断后面的是否比前面的路径短，如果路径短，则相同节点允许重复

其他的就看代码吧，比较容易理解

### 代码

```c

#define MAX_MAZE_SIZE (30 * 30)
#define DEAFULT_SIZE 2
#define MAX_DIRECT 4
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

typedef struct WAYS {
    int **maze;
    int mazeSize;
    int *mazeColSize;
    int *ball;
    int *hole;
} WAYS_S;

typedef struct WAYSINFO {
    int ballNum;
    char *record;
} WANYSINFO_S;


void AddOneRecord(WANYSINFO_S *waysRecord, int *listNum, char *way, int pos, int ballNum)
{
    char *record = NULL;

    record = (char *)malloc((pos + 1) * sizeof(char));
    if (record == NULL) {
        return;
    }
    memset(record, 0x0, (pos + 1) * sizeof(char));
    memcpy(record, way, pos + 1);
    waysRecord[*listNum].record = record;
    waysRecord[*listNum].ballNum = ballNum;
    *listNum = *listNum + 1;
    return;
}
typedef struct BALLINFO {
    int row;
    int col;
    int ballNum;
    int pos;
    char way[MAX_MAZE_SIZE];
} BALLINFO_S;

int GetNextStep(WAYS_S *waysinfo, WANYSINFO_S *waysRecord, int *listNum, int *row, int *col, char *way, int pos,
    int ballNum, int direct)
{
    int  directInfo[MAX_DIRECT][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
    char director[MAX_DIRECT] = { 'u','d','l','r' };

    int num;
    num = 0;
    for (num = 0; num < MAX_MAZE_SIZE; num++) {
        *row = *row + directInfo[direct][0];
        *col = *col + directInfo[direct][1];
        if ((*row < 0) || (*row >= waysinfo->mazeSize)) {
            break;
        }

        if ((*col < 0) || (*col >= waysinfo->mazeColSize[*row])) {
            break;
        }

        if (waysinfo->maze[*row][*col] == 1) {
            break;
        }

        if ((*row == waysinfo->ball[0]) && (*col == waysinfo->ball[1])) {
            num = 0;
            break;
        }
        if ((*row == waysinfo->hole[0]) && (*col == waysinfo->hole[1])) {
            way[pos] = director[direct];
            AddOneRecord(waysRecord, listNum, way, pos + 1, ballNum + num);
            num = 0;
            break;
        }
    }
    return num;
}

int IsNeedReVisit(int row, int col, int ballNum, BALLINFO_S *nodeList, int listNum)
{
    for (int index = 0; index < listNum; index++) {
        if (row != nodeList[index].row) {
            continue;
        }
        if (col != nodeList[index].col) {
            continue;
        }

        if (ballNum <= nodeList[index].ballNum) {
            return 1;
        }
        return 0;
    }
    return 0;
}

void GetWaysList(WAYS_S *waysinfo, WANYSINFO_S *waysRecord, int *listNum, int curRow, int curCol, char *flag)
{
    flag[curRow * waysinfo->mazeColSize[curRow] + curCol] = 1;

    /* add first node */
    BALLINFO_S *nodeList = (BALLINFO_S *)malloc(sizeof(BALLINFO_S) * MAX_MAZE_SIZE * 2);
    if (nodeList == NULL) {
        return;
    }

    memset(nodeList, 0x0, sizeof(BALLINFO_S) * MAX_MAZE_SIZE * 2);

    int begin;
    int end;

    begin = 0;
    end = 0;
    nodeList[0].row = curRow;
    nodeList[0].col = curCol;
    end++;
    int  directInfo[MAX_DIRECT][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
    char director[MAX_DIRECT] = { 'u','d','l','r' };

    while (begin < end) {
        if (end >= MAX_MAZE_SIZE - 1) {
            begin++;
            break;
        }

        for (int index = 0; index < MAX_DIRECT; index++) {
            strncpy(nodeList[end].way, nodeList[begin].way, nodeList[begin].pos);
            nodeList[end].pos = nodeList[begin].pos;
            nodeList[end].ballNum = nodeList[begin].ballNum;

            int row;
            int col;
            int num;
            row = nodeList[begin].row;
            col = nodeList[begin].col;
            num = GetNextStep(waysinfo, waysRecord, listNum, &row, &col, nodeList[end].way, nodeList[end].pos,
                nodeList[end].ballNum, index);
            if (num == 0) {
                continue;
            }
            row = row - directInfo[index][0];
            col = col - directInfo[index][1];
            if ((row == nodeList[begin].row) && (col == nodeList[begin].col)) {
                continue;
            }

            if ((flag[row * waysinfo->mazeColSize[row] + col] != 0) &&
                (IsNeedReVisit(row, col, nodeList[end].ballNum + num, nodeList, end) != 1)) {
                continue;
            }

            // add node
            nodeList[end].row = row;
            nodeList[end].col = col;
            nodeList[end].ballNum += num;
            nodeList[end].way[nodeList[end].pos] = director[index];
            nodeList[end].pos = nodeList[end].pos + 1;
            flag[row * waysinfo->mazeColSize[row] + col] = 1;
            end++;
            if (end >= MAX_MAZE_SIZE - 1) {
                break;
            }
        }
        begin++;
    }
    return;
}

int Compare(const void *a, const void *b)
{
    WANYSINFO_S *old = (WANYSINFO_S *)a;
    WANYSINFO_S *input = (WANYSINFO_S *)b;
    if (old->ballNum != input->ballNum) {
        return (old->ballNum - input->ballNum);
    }
    return strcmp(old->record, input->record);
}

char *findShortestWay(int **maze, int mazeSize, int *mazeColSize, int *ball, int ballSize, int *hole, int holeSize)
{
    char *ways = NULL;

    ways = (char *)malloc(MAX_MAZE_SIZE * sizeof(char));
    if (ways == NULL) {
        return NULL;
    }
    memset(ways, 0x0, MAX_MAZE_SIZE * sizeof(char));
    if ((ballSize != DEAFULT_SIZE) || (holeSize != DEAFULT_SIZE)) {
        return ways;
    }

    if (mazeSize < 1) {
        return ways;
    }

    if ((ball[0] >= mazeSize) || (hole[0] >= mazeSize)) {
        return ways;
    }

    if ((ball[1] >= mazeColSize[0]) || (hole[1] >= mazeColSize[0])) {
        return ways;
    }

    WAYS_S waysinfo;
    waysinfo.maze = maze;
    waysinfo.mazeSize = mazeSize;
    waysinfo.ball = ball;
    waysinfo.hole = hole;
    waysinfo.mazeColSize = mazeColSize;
    char flag[MAX_MAZE_SIZE];
    memset(flag, 0x0, sizeof(flag));
    int listNum = 0;

    WANYSINFO_S waysRecord[MAX_MAZE_SIZE + 1];
    memset(waysRecord, 0x0, sizeof(waysRecord));
    GetWaysList(&waysinfo, waysRecord, &listNum, ball[0], ball[1], flag);

    if (listNum == 0) {
        strcpy(ways, "impossible");
        return ways;
    }
    qsort(waysRecord, listNum, sizeof(waysRecord[0]), Compare);

    strcpy(ways, waysRecord[0].record);
    for (int i = 0; i < listNum; i++) {
        free(waysRecord[i].record);
    }
    return ways;
}
```