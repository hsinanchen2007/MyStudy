1：从左上角向右向下遍历，算出每个节点向上和向左的延伸轴长度
2：从右下角向左向上遍历，算出每个节点向下和向右的延伸轴长度，同时获取四个延伸长度的最小值就是加号的阶数，最后一次比较获取最大阶加号

![image.png](https://pic.leetcode-cn.com/b85d48ebb912ceb03489c35f33674f2db9595ddb64bb39cb02afbd47e6e55aa9-image.png)


```
#define MAX_GRID_SIZE 500
#define MIN(a, b) (((a) > (b)) ? (b) : (a))
#define MIN_FOUR(a,b,c,d)   MIN(MIN(a,b), MIN(c,d))
typedef struct tagGridNode {
    int flag;
    int up;
    int down;
    int left;
    int right;
} GRID_NODE;

int orderOfLargestPlusSign(int N, int** mines, int minesSize, int* minesColSize){
    GRID_NODE grid[MAX_GRID_SIZE][MAX_GRID_SIZE] = { 0 };
    int i, j;
    int stage = 0;
    int curStage = 0;\
    GRID_NODE *PNode= NULL;

    if (mines == NULL || minesSize == 0) {
        return (N + 1)/2;
    }
    
    for (i = 0; i < minesSize; i++) {
        grid[mines[i][0]][mines[i][1]].flag = 1;
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            PNode = &grid[i][j];
            if (PNode->flag == 0) {
                PNode->left = 1;
                PNode->up = 1;
                if (j > 0) {
                    PNode->left += grid[i][j - 1].left;
                }

                if (i > 0) {
                    PNode->up += grid[i - 1][j].up;
                }
            }
        }
    }

    for (i = N - 1; i >= 0; i--) {
        for (j = N - 1; j >= 0; j--) {
            PNode = &grid[i][j];
            if (PNode->flag == 0) {
                PNode->right = 1;
                PNode->down = 1;
                if (i < N - 1) {
                    PNode->down += grid[i + 1][j].down;
                }

                if (j < N - 1) {
                    PNode->right += grid[i][j + 1].right;
                }

                curStage =  MIN_FOUR(PNode->left, PNode->right, PNode->up, PNode->down);
                if (curStage > stage) {
                    stage = curStage;
                }
            }
        }
    }

    return stage;
}
```