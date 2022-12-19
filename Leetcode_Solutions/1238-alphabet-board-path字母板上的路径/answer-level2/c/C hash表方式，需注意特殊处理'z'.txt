### 解题思路
此处撰写解题思路

### 代码

```c
struct node {
    int x;
    int y;
    char key;
};
char * alphabetBoardPath(char * target) {
    char board[6][5] = {
        { 'a','b','c','d','e'},
        { 'f','g','h','i','j' } ,
        { 'k','l','m','n','o' } ,
        { 'p','q','r','s','t' } ,
        { 'u','v','w','x','y' },
        { 'z'} };
    int boardColSize[6] = { 5,5,5,5,5,1 };
    struct node position[26];
    int i, j;
    int len;

    if (target == NULL) {
        return NULL;
    }

    // 存储每个字母所在位置信息
    for (i = 0; i < 6; i++) {
        for (j = 0; j < boardColSize[i]; j++) {
            position[board[i][j] - 'a'].x = i;
            position[board[i][j] - 'a'].y = j;
        }
    }
    len = strlen(target);

    char *rlt = (char *)malloc(sizeof(char) * 1000);
    int idx = 0;
    int x, y;
    struct node start;
    start.x = 0;
    start.y = 0;

    for (i = 0; i < len; i++) {
        // 其中字母Z特殊处理，因为如果从非Z到目标Z，不能直接往下，因为不能走到board中最后一行。需先往左，再往下。
        if (target[i] == 'z' && board[start.x][start.y] != 'z') {
            y = position[target[i] - 'a'].y;
            while ((y - start.y) != 0) {
                if ((y - start.y) > 0) {
                    rlt[idx++] = 'R';
                    y--;
                } else if ((y - start.y) < 0) {
                    rlt[idx++] = 'L';
                    y++;
                }
            }

            x = position[target[i] - 'a'].x;
            while ((x - start.x) != 0) {
                if ((x - start.x) > 0) {
                    rlt[idx++] = 'D';
                    x--;
                } else if ((x - start.x) < 0) {
                    rlt[idx++] = 'U';
                    x++;
                }
            }
        } else {
            // 其余情况下，均可先上下移动，再左右移动
            x = position[target[i] - 'a'].x;
            while ((x - start.x) != 0) {
                if ((x - start.x) > 0) {
                    rlt[idx++] = 'D';
                    x--;
                }
                else if ((x - start.x) < 0) {
                    rlt[idx++] = 'U';
                    x++;
                }
            }

            y = position[target[i] - 'a'].y;
            while ((y - start.y) != 0) {
                if ((y - start.y) > 0) {
                    rlt[idx++] = 'R';
                    y--;
                }
                else if ((y - start.y) < 0) {
                    rlt[idx++] = 'L';
                    y++;
                }
            }
        }
        rlt[idx++] = '!';
        // 更新起始位置
        start.x = position[target[i] - 'a'].x;
        start.y = position[target[i] - 'a'].y;
    }
    rlt[idx] = 0;

    return rlt;
}
```