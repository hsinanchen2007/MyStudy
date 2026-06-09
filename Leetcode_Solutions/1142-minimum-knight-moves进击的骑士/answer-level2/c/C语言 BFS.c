直接把目标转成绝对值，除了1,1特殊处理一下，其他位置所需步数和符号没关系，这样可以不用搞偏移。
```
#define MAX_SIZE1 1000
#define MAX_SIZE 1000000
int minKnightMoves(int x, int y){
    int book[MAX_SIZE1][MAX_SIZE1] = {0};
    int que[MAX_SIZE][3] = {0};
    int head = 0;
    int rear = 0;
    x = abs(x);
    y = abs(y);
    if (x == 1 && y == 1) {
        return 2;
    }
    que[rear][0] = 0;
    que[rear][1] = 0;
    que[rear][2] = 0;
    int i = 0;
    int j = 0;
    rear++;
    
    int direct[] = {-2, -1, 2, 1, 2, -1, -2, 1, -2};
    while (head < rear) {
        i = que[head][0];
        j = que[head][1];
        int step = que[head][2];
        if (i < 0 || j < 0 || book[i][j] == 1) {
            head++;
            continue;
        }
        book[i][j] = 1;
        if (i == x && j == y) {
            return step;
        }
        for (int k = 0; k < 8; k++) {
            int m = i + direct[k];
            int n = j + direct[k + 1];        
            que[rear][0] = m;
            que[rear][1] = n;
            que[rear][2] = step + 1;
            rear++;
        }
        head++;
    }
    return 0;
}
```
