### 解题思路
就是BFS搜索。挺简单。遗憾的是，C没有hashmap。map我用一维数组来表示。
### 代码

```c
typedef struct node_t {
    int val;
    int step;
} Node;
Node queue[10000];
int head;
int tail;

int coinChange(int* coins, int coinsSize, int amount){
    head = tail = 0;
    if (coins == NULL || coinsSize <= 0) return -1;
    if (amount == 0) return 0;
    char *map = malloc(amount + 1);
    memset(map, 0, amount + 1);

    queue[tail].val = amount;
    queue[tail].step = 0;
    tail++;
    map[amount] = 1;
    while (head < tail) {
        int sum = queue[head].val;
        int step = queue[head].step;
        for (int i = 0; i < coinsSize; i++) {
           int nextSum = sum - coins[i];
           if (nextSum == 0) {
               return step + 1;
           } else if (nextSum > 0) {
               if (map[nextSum] == 0) {
                    queue[tail].val = nextSum;
                    queue[tail].step = step + 1;
                    tail++;
                    map[nextSum] = 1;
               }
           }
        }
        head++;
    }
    return -1;
}
```