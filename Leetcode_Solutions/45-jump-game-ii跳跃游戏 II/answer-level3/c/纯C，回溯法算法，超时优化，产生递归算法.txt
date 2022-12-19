### 解题思路
方法一：回溯法，始终超时，因此考虑优化
1,边界条件，当前位置 iCurPos >= numsSize
.    iCurPos > numsSize  返回错误，返回至上一位置，进行长一步的试探，所以不存在
.    iCurPos = numsSize 保存步数结果，并且返回上两层，进行长一步的试探
2,回溯调用
.    从 1 - nums[iCurPos] 开始调用回溯函数，返回true则j结束当前层的探测

优化一，增加判断如果 iCurPos + num[iCurPos] >= numsSize 的话，可以直接结束
优化二，当pCurStep >= pMinStep 当前步数已经大于已有的最小步数，可以直接结束当前层探测
优化三，走每步的时候都考虑走最大的一步，每一步都决定出能够走出的最大一步，直到终点，由此找到了第二种解法，见方法二


方法二：递归法
1，在当前位置 iCurPos 上找出能够探寻最大长度的点 MAX(iCurPos + nums[i])  i=1 -> num[iCurPos]
2，结束条件 (iCurPos + nums[iCurPos]) > numsSize 

### 代码

```c

//方法二：递归法
//1，在当前位置 iCurPos 上找出能够探寻最大长度的点 MAX(iCurPos + nums[i])  i=1 -> num[iCurPos]
//2，结束条件 (iCurPos + nums[iCurPos]) > numsSize 

//探寻函数,探寻出当前位置能够达到最大长度的点
int seekMaxJump(int* nums, int numsSize, int iCurPos){
    int     i       = 0;
    int     iMax    = 0;
    int     iMaxPos = 0;

    for (i = 1; i <= nums[iCurPos]; i++)
    {
        if ((i + nums[iCurPos + i]) >= iMax)
        {
            iMax = i + nums[iCurPos + i];
            iMaxPos = iCurPos + i;
        }
    }

    return iMaxPos;
}

//递归函数
void recursiveJump(int* nums, int numsSize, int* pMinStep, int iCurPos){
    int     iNextPos    = 0;
    int     iRet        = 0;

    *pMinStep += 1;

    //1，结束条件
    if ((iCurPos + nums[iCurPos]) >= numsSize - 1)
    {
        return;
    }

    //2，找出当前位置能够探寻最大长度的位置
    iNextPos = seekMaxJump(nums, numsSize, iCurPos);

//    printf("[cur=%d][num=%d][next=%d][num=%d][step=%d]\n", iCurPos, nums[iCurPos], iNextPos, nums[iNextPos], *pMinStep);

    //3，递归调用
    recursiveJump(nums, numsSize, pMinStep, iNextPos);

    return;
}

int jump(int* nums, int numsSize){
    int     iMinStep    = 0;

    if ((NULL == nums) || (1 == numsSize)) return iMinStep;

    recursiveJump(nums, numsSize, &iMinStep, 0);

    return iMinStep;
}


/*
//方法一：回溯法
//1,边界条件，当前位置 iCurPos >= numsSize
//  iCurPos > numsSize  返回错误，返回至上一位置，进行长一步的试探，所以不存在
//  iCurPos = numsSize 保存步数结果，并且返回上两层，进行长一步的试探
//2,回溯调用
//  从 1 - nums[iCurPos] 开始调用回溯函数，返回true则j结束当前层的探测
//优化一，增加判断如果 iCurPos + num[iCurPos] >= numsSize 的话，可以直接结束
//优化二，当pCurStep >= pMinStep 当前步数已经大于已有的最小步数，可以直接结束当前层探测
//优化三，走每步的时候都考虑走最大的一步，每一步都决定出能够走出的最大一步，直到终点，由此找到了第二种解法，见方法二
bool backTrackJump(int* nums, int numsSize, int* pMinStep, int* pCurStep, int iCurPos){
    int     i       = 0;

//    printf("[1][Min=%d][cur=%d][pos=%d][num=%d]\n", *pMinStep, *pCurStep, iCurPos, nums[iCurPos]);

    //1，边界条件,判断走到了最后位置则判断最小步数后返回
    if (iCurPos == numsSize - 1)
    {
        if ((*pMinStep) > (*pCurStep))
        {
            *pMinStep = *pCurStep;
        }
        return true;
    } 

    //特殊处理一
    if (0 == nums[iCurPos])
    {
        return false;
    }

    //优化二
    if ((*pCurStep) >= (*pMinStep))
    {
        return true;
    }

    //2,回溯调用，当前步数加1，循环试探当前位置的步数
    (*pCurStep) += 1;
    for (i = 1; i <= nums[iCurPos]; i++)
    {
        //优化一
        if ((iCurPos + nums[iCurPos]) >= numsSize - 1)
        {
            i = numsSize - iCurPos - 1;
        }

        if (backTrackJump(nums, numsSize, pMinStep, pCurStep, iCurPos + i))
        {
            //3,如果当前位置走 i 步正好到达边界，则直接结束该位置的后续试探
            break;
        }
    }

    //4,当前位置试探结束，回退到上一步，步数减1
    (*pCurStep) -= 1;
    return false;
}

int jump(int* nums, int numsSize){
    int     iMinStep    = numsSize;
    int     iCurStep    = 0;

    backTrackJump(nums, numsSize, &iMinStep, &iCurStep, 0);

    return iMinStep;
}
*/
```