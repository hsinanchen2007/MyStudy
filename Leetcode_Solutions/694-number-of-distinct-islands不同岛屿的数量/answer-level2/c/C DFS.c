```

#define MAX 50
#define STACK_NODE_MAX  (25 * 25 + 1)
typedef struct tagNodePos {
    int row;
    int col;
} NodePos;

typedef struct tagStackData {
    NodePos pos[STACK_NODE_MAX];
    int index;
} StackData;

typedef struct tagStackList {
    StackData stackList[STACK_NODE_MAX];
    int cnt;
} StackList;

int g_direct[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1 ,0}};

void PushStack(StackData *stack, NodePos src, NodePos posData)
{
    if (stack->index >= STACK_NODE_MAX) {
        return;
    }
    int index = stack->index;
    /* 记录岛屿节点与起始遍历位置的相对坐标 */
    stack->pos[index].row = posData.row - src.row;
    stack->pos[index].col = posData.col - src.col;
    stack->index++;
    return;
}

int IsSameNode(StackData pre, StackData next)
{
    /* 如果节点个数不同，则形状一定不同 */
    if (pre.index != next.index) {
        return -1;
    }

    /* 由于岛屿不能旋转，所以依次比较节点数值 */
    for (int i = 0; i < pre.index; i++) {
        if ((pre.pos[i].row != next.pos[i].row) || 
            (pre.pos[i].col != next.pos[i].col)) {
            return -1;
        }
    }

    return 0;
}

int GetDiffCnt(StackList *sList)
{
    int cnt = 0;
    for (int i = 0; i < cnt; i++) {
        OutPutStack(sList->stackList[i]);
    }

    for (int i = 0; i < sList->cnt - 1; i++) {
        StackData cur = sList->stackList[i];
        if (cur.index == 0) {
            continue;
        }
        for (int j = i + 1; j < sList->cnt; j++) {
            StackData next = sList->stackList[j];
            if (IsSameNode(cur, next) == 0) {
                sList->stackList[j].index = 0;
            }
        }
    }

    for (int i = 0; i < sList->cnt; i++) {
        if (sList->stackList[i].index != 0) {
            cnt++;
        }
    }

    return cnt;
}

void dfs(int **grid, NodePos src, NodePos step, NodePos dst, StackData *stack)
{
    /* 边界判断 */
    if ((step.row < 0) || (step.col < 0) || (step.row >= dst.row) || (step.col >= dst.col)) {
        return;
    }

    if (grid[step.row][step.col] == 0) {
        return;
    }

    grid[step.row][step.col] = 0;
    PushStack(stack, src, step);

    for (int i = 0; i < 4; i++) {
        NodePos next = {
            .row = step.row + g_direct[i][0],
            .col = step.col + g_direct[i][1]
        };
        dfs(grid, src, next, dst, stack);
    }

    return;
}

int numDistinctIslands(int **grid, int gridSize, int* gridColSize){
    if (grid == NULL || gridSize == 0 || gridColSize == NULL) {
        return 0;
    }

    NodePos dst = {
        .row = gridSize,
        .col = *gridColSize
    };

    StackList stackList = {0};
    for (int i = 0; i < dst.row; i++) {
        for (int j = 0; j < dst.col; j++) {
            if (grid[i][j] == 1) {
                StackData *stack = &(stackList.stackList[stackList.cnt]);
                NodePos src = {
                    .row = i,
                    .col = j
                };
                
                /* DFS 深搜查找岛屿，并将每个坐标压栈 */
                dfs(grid, src, src, dst, stack);
                stackList.cnt++;
            }
        }
    }

    return GetDiffCnt(&stackList);
}
```

![image.png](https://pic.leetcode-cn.com/36b6bd26380f6a4eb9a08f839e4cfb7429d7d6e3f06a27f91439c40c1d5419a6-image.png)
