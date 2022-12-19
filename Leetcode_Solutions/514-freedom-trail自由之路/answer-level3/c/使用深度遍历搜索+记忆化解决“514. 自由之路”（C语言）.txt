### 解题思路
典型的DFS类型题目，通过记忆化进行剪枝，这里给出C语言的实现方法。

注意，由于存在递归调用，该方法速度会慢于DP，但胜在思路简单直接。

1.开辟memo数组用于记录结果，memo[i][j]表示在ring的i位置开始，查找key的j位置的字符到结束的最短长度

2.从i=0,j=0开始深度遍历

3.如果memo[i][j]已经有结果，则直接返回

4.遍历ring，找到所有符合的位置

5.对于一个符合的位置，计算移动步数，这里注意要找正向或反向的最小步数

6.基于该位置，使用递归函数找j+1的字符

7.直至结束。

![image.png](https://pic.leetcode-cn.com/5e4d579e6580e89f5d64e4fb3f4abd191d487cc009f1c279872cf9ce5444bf12-image.png)


### 代码

```c
#include <limits.h>
#define MMIN(a, b)      ((a) < (b)? (a) : (b))

char *rr;
int rlen;
char *kk;
int klen;

int memo[100][100];

//返回从rid，和kid的位置遍历完序列的最小步骤
int helper(int rid, int kid) {
    if(kid == klen) {
        return 0;
    }

    if(memo[rid][kid] != 0) {
        return memo[rid][kid] - 1;
    }

    int min_steps = INT_MAX;
    int cur_steps = 0;

    //遍历ring，找到所有的相同位置
    for(int i = 0; i < rlen; i++) {
        //实际访问位置
        int id = (rid + i) % rlen;
        if(rr[id] == kk[kid]) {
            cur_steps = MMIN(i, rlen - i);

            int ret = helper(id, kid + 1);

            min_steps = MMIN(min_steps, ret + cur_steps);
        }
    }

    memo[rid][kid] = min_steps + 1;

    return min_steps;
}

//【算法思路】DFS。
int findRotateSteps(char * ring, char * key){
    rr = ring;
    rlen = strlen(ring);
    kk = key;
    klen = strlen(key);

    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            memo[i][j] = 0;
        }
    }

    int ret = helper(0, 0);

    return ret + klen;
}
```