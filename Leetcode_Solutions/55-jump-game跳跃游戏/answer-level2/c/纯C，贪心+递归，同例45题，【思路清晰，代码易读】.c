### 解题思路
方法一：递归法贪心
1, 每一个位置 pos ，找出能够到达最远位置的下一个位置
2, 再以下一个位置递归调用，计算下一个能够到达最远位置的点
3, 结束条件：当能到达的最远位置超过 numsSize 时则返回true
4, 结束条件：当某一个点为0时则返回false
### 代码

```c
//方法一：递归法贪心
//每一个位置 pos ，找出能够到达最远位置的下一个位置
//再以下一个位置递归调用，计算下一个能够到达最远位置的点
//结束条件：当能到达的最远位置超过 numsSize 时则返回true
//结束条件：当某一个点为0时则返回false

//函数一：在当前位置iCurPos 从1-nums[iCurPos]向后探寻，找到能够跳到最远的下一个点
int seekNextPos(int* nums, int numsSize, int iCurPos){
    int     i           = 0;
    int     iNextPos    = 0;
    int     iMaxPos     = 0;

    for (i = 1; i <= nums[iCurPos]; i++)
    {
        if (i + nums[iCurPos + i] >= iMaxPos)
        {
            iMaxPos = i + nums[iCurPos + i];
            iNextPos = iCurPos + i;
        }
    }
    return iNextPos;
}

//函数二：递归函数
bool recursiveJump(int* nums, int numsSize, int iCurPos){
    int     iNextPos    = 0;

//    printf("[1][Cur=%d][val=%d]\n", iCurPos, nums[iCurPos]);

    //1, 结束条件
    if (nums[iCurPos] == 0) return false;
    if (nums[iCurPos] + iCurPos >= numsSize - 1) return true;

    //2,计算当前位置能够到达最远位置的下一个点
    iNextPos = seekNextPos(nums, numsSize, iCurPos);

    return recursiveJump(nums, numsSize, iNextPos);
}

bool canJump(int* nums, int numsSize){
    bool    bRet    = false;
    
    if (NULL == nums) return false;
    if (1 == numsSize) return true;

    bRet = recursiveJump(nums, numsSize, 0);

    return bRet;
}
```