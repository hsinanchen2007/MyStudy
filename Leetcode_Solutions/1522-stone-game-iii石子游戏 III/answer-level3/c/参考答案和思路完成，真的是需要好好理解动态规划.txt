### 解题思路
/* *
 * 动态规划：
 * 1、每次都是获取当前最优值
 * 2、如果只有1个，则获取最后一个
 * 3、如果多余1个，则获取当前值以及当前和减去后面最优的值（需要保证自己获取的值比对方获取的值大）
 */

### 代码

```c
/* *
 * 动态规划：
 * 1、每次都是获取当前最优值
 * 2、如果只有1个，则获取最后一个
 * 3、如果多余1个，则获取当前值以及当前和减去后面最优的值（需要保证自己获取的值比对方获取的值大）
 */
#define MAX_CHOOSE_POS 3
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

char *stoneGameIII(int *stoneValue, int stoneValueSize)
{
    if (stoneValueSize + 2 < stoneValueSize) {
        return NULL;
    }

    int *dp = NULL;
    dp = malloc((stoneValueSize + 2) * sizeof(int));
    if (dp == NULL) {
        return NULL;
    }
    memset(dp, 0x0, (stoneValueSize + 2) * sizeof(int));

    for (int index = stoneValueSize - 1; index >= 0; index--) {
        int goal;
        int sum;
        sum = 0;
        goal = INT_MIN;

        for (int pos = index; pos < MIN(index + MAX_CHOOSE_POS, stoneValueSize); pos++) {
            sum += stoneValue[pos];
            int competitor;
            competitor = sum - dp[pos + 1];
            goal = MAX(goal, competitor);
        }
        dp[index] = goal;
    }

    char *result = NULL;
    result = malloc(10);

    if (dp[0] > 0) {
        printf("Alice");
        free(dp);
        dp = NULL;
        strcpy(result, "Alice");
        return result;
    } else if (dp[0] < 0) {
        printf("Bob");
        free(dp);
        dp = NULL;
        strcpy(result, "Bob");
        return result;
    } else {
        printf("Tie");
        free(dp);
        dp = NULL;
        strcpy(result, "Tie");
        return result;
    }
}
```