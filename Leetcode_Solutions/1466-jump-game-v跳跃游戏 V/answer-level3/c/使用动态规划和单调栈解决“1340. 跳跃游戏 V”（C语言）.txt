### 解题思路
本题可以按照动态规划思路解决，dp[i]表示从i点最多可以发生的跳跃次数，dp[i]在求解过程中需要不断调整。

本题的难点在于，当计算i点时，dp[i]可以由之前小于arr[i]的dp[j]得到，但是还要更新大于arr[i]的dp值。

从题目分析，这个更新过程是向左传递的，即会影响到前面范围内大于自己的点，题解中使用last_id完成这一传递过程。

至于如何快速找到向左的更大值，使用单调栈实现。

1.开辟数组dp[],用于存放每一点最多可以跳跃次数。

2.初始化dp[i] = 1,方便后续计算

3.遍历arr，对于arr[i]:

4.首先向左遍历所有小于arr[i]的元素，更新自己的dp[i]

5.挤掉栈顶小于arr[i]的“气泡”

6.从顶向底遍历栈，当stk[j]的数据大于arr[i]，则dp[j] = max(dp[j], dp[last_id] + 1);

7.特别注意，当stk[j]的数据等于arr[i]，则last_id选择dp值更大的id

![image.png](https://pic.leetcode-cn.com/e72dbcc3c0fdf30be8aaeeef12e0d9d84e6692d1ca865fac638bb1c4829665f0-image.png)


### 代码

```c
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MMAX(a, b)        ((a) > (b)? (a) : (b))

//【算法思路】动态规划+单调栈。dp[i]表示第i个点最多的跳跃次数
// 关键点：
// 1.单调栈保存所有更大的点，用于数据刷新。
// 2.每次刷新时，范围根据last_id向前扩展
// 3.栈中相同数据的更新策略是，选择dp更大的做为last_id
int maxJumps(int* arr, int arrSize, int d){
    int *dp = (int *)calloc(arrSize, sizeof(int));
    int *stk = (int *)calloc(arrSize, sizeof(int));
    int ssize = 0;

    for(int i = 0; i < arrSize; i++) {
        dp[i] = 1;
        //printf("%d-%d  ", i, arr[i]);
    }
    //printf("\n");

    dp[0] = 1;
    stk[ssize++] = 0;

    for(int i = 1; i < arrSize; i++) {
        //先遍历所有小于自己的位置
        for(int j = i - 1; j >= i - d; j--) {
            if(j < 0 || arr[i] <= arr[j]) {
                break;
            }

            dp[i] = MMAX(dp[i], dp[j] + 1);
        }

        //挤出栈中气泡
        while(ssize > 0) {
            if(arr[stk[ssize - 1]] >= arr[i]) {
                break;
            }
            ssize--;
        }

        //根据队列刷新数据,递增数据才可以刷新
        int last_id = i;
        for(int j = ssize - 1; j >= 0; j--) {
            int jid = stk[j];
            if(last_id - jid > d) {
                break;
            }
            
            if(arr[jid] > arr[last_id]) {
                //递增数据，更新dp
                dp[jid] = MMAX(dp[jid], dp[last_id] + 1);
                last_id = jid;
            } else if(arr[jid] == arr[last_id]) {
                //关键点：相同数据，选择dp值更大的一个
                last_id = dp[jid] > dp[last_id]? jid : last_id;
            } else {
                break;
            }
        }

        //插入新数据
        stk[ssize++] = i;
/*
        printf("<%d>dp:  ", i);
        for(int j = 0; j < arrSize; j++) {
            printf("%d-%d  ", j, dp[j]);
        }
        printf("\n");
*/
    }

    //找到最大dp[i]
    int ret = 1;
    for(int i = 0; i < arrSize; i++) {
        ret = MMAX(ret, dp[i]);
    }

    return ret;
}
```