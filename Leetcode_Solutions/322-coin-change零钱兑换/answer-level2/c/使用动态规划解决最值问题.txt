### 解题思路
1. 最值问题可以使用动态规划求解：
   假设需要拼出硬币k，使用了n个硬币，分别为：
       a1 + a2 + a3 + ... + an;
   则前n-1个一定是最少拼出k-an的。
   问题规模减小了。
2. 转移方程
   假设只有1， 2， 5中硬币，则
   f[k] = min {f[k-1]+1， f[k-2]+1, f[k-5]+1}
3. 当k = 0时，f[0] = 0; 当拼不出来时，使用0x7FFFFFFF表示。
4. 从小到大计算每种币值的拼法，因为这样才能利用前面的计算结果。

### 代码

```c
#define MIN(x, y) ((x) < (y)) ? (x) : (y)

int coinChange(int* coins, int coinsSize, int amount){
    int cnt;
    int *f = (int *) malloc((amount + 1) * sizeof(int));
    f[0] = 0;
    /* 计算每种硬币最少的硬币数 */
    for (int i = 1; i <= amount; i++) {
        /* 默认拼不出来 */
        f[i] = 0x7FFFFFFF;
        /* 最后一步  */
        for (int j = 0; j < coinsSize; j++) {
            if (i >= coins[j] && f[i-coins[j]] != 0x7FFFFFFF) {
                f[i] = MIN(f[i], f[i - coins[j]]+1);
            }
        }
    }

    if (f[amount] == 0x7FFFFFFF) {
        cnt = -1;
    } else {
        cnt = f[amount];
    }
    
    free(f);
    return cnt;
}
```