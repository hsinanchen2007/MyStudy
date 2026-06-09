### 解题思路
经典的**游戏输赢类**问题，通常使用DFS+memo实现，这里给出C语言的解法。

本题特殊点在于，记忆化需要使用位运算实现，并且由于**选择的位图决定了结果数据大小，因此第二维度可以省略**，降低空间占用。

另外，C语言使用calloc性能开销要远远优于for循环初始化。

![image.png](https://pic.leetcode-cn.com/7d2f849786a66f45269092e96cef103c54e92bb167fd14d90dc0ca9ce8caec31-image.png)


### 代码

```c
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MMAX(a, b)        ((a) > (b)? (a) : (b))
#define MMIN(a, b)        ((a) < (b)? (a) : (b))

// 记录当前数字使用情况下的输赢，赢为1，输为2
int *memo;

bool helper(int max_num, int tar, int mask) {
    if(memo[mask] != 0) {
        //printf("TRUE:tar = %d, mask = 0x%x\n", tar, mask);
        return memo[mask] == 1;
    }

    for(int i = max_num; i > 0; i--) {
        int bit = 1 << (i - 1);
        if((bit & mask) != 0) {
            continue;
        }

        int new_mask = mask | bit;

        if(i >= tar) {
            memo[mask] = 1;
            return true;
        }

        bool ret = helper(max_num, tar - i, new_mask);

        //对手失败，则表示自己获胜
        if(ret == false) {
            memo[mask] = 1;
            //printf("TRUE:tar = %d, mask = 0x%x\n", tar, mask);
            return true;
        }
    }

    memo[mask] = 2;
    //printf("FALSE:tar = %d, mask = 0x%x\n", tar, mask);
    return false;
}

//【算法思路】dfs+memo+位操作。游戏输赢类问题，使用DFS逐轮求解。
// 注意：记忆化这里有一个隐含约束，即数字使用图样一旦确定，则生成结果必然确定，利用这一点降低记忆化内存空间。
bool canIWin(int maxChoosableInteger, int desiredTotal){
    int sum = 0;
    for(int i = 1; i <= maxChoosableInteger; i++) {
        sum += i;
    }

    if(sum < desiredTotal) {
        return false;
    }

    //初始化
    memo = (int *)calloc(pow(2, maxChoosableInteger), sizeof(int));

    int mask = 0;
    bool ret = helper(maxChoosableInteger, desiredTotal, mask);

    return ret;
}
```