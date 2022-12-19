### 解题思路
整体和题解1的思路一样
只有四种情况满足条件：
1 两种次数，只有1个多1次 
2 两种次数，1个1次
3 都只出现1次
4 和长度相同的次数

直接按照条件去思考，比较难想到的是如何计算存在两种计数，如何计算两种计数的差值。
这里主要解释实现中的两个点：
1 使用两个哈希表，1个记录当前数字出现的次数，一个记录当前次数出现的次数。这里实际上是将各种次数的累积，有点动态规划的思想（次数的个数）。
当前次数出现的次数是一个累积过程，比如1 1 2，这里出现1次的是2个，出现2次的是1个。
最后按条件判断即可。
2 条件1和条件4的判断条件一样，实际上条件4是一个特殊的条件1，即少1次的数据相同。

### 代码

```c
/*
只有四种情况满足条件：
1 两种次数，只有1个多1次 
2 两种次数，1个1次
3 都只出现1次
4 和长度相同的次数

*/
#define MAXLEN 100000
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define PRINTF // printf
int maxEqualFreq(int* nums, int numsSize){
    int hashCount[MAXLEN] = {0};
    int hashFreq[MAXLEN] = {0};
    int iRet = 0;
    int maxcnt = 0;
    for (int i = 0; i < numsSize; i++) {
        (hashCount[nums[i]])++; // 数字出现的次数
        (hashFreq[hashCount[nums[i]]])++; // 当前次数的个数
        maxcnt = MAX(maxcnt, hashCount[nums[i]]); // 当前最大的次数
        if((hashFreq[maxcnt] == 1) && ((hashFreq[maxcnt - 1] * (maxcnt - 1) + 1) == (i + 1))) { // Case 1/4 Match
            iRet = (i + 1);
            continue;
        }
        if(((hashFreq[1] - hashFreq[maxcnt]) == 1) && (((hashFreq[maxcnt] * maxcnt) + 1) == (i + 1))) { // Case 2 Match
            iRet = (i + 1);
            continue;
        }
    }
    if (maxcnt == 1) {
        iRet = numsSize;
    }
    return iRet;
}
```