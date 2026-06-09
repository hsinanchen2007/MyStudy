### 解题思路

![image.png](https://pic.leetcode-cn.com/e749eecbffb3e7b4a48edcc9f1b5f722276ef7be6e5b851ce38b0b3106a07217-image.png)

方法比较暴力，重点就是求最大深度。最大深度的一半不够之前都分给A，如果够了，就都分给B。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char * seq, int* returnSize){
    int len;
    int i;
    int ileftFlag  = 0;
    int iRightFlag = 0;
    int iMax = 0;
    int iMaxTotal = 0;
    int iDepth = 0;

    if('\0' == seq[0])
    {
        *returnSize = 0;
        return returnSize;
    }

    for(i=0; seq[i] !='\0'; i++)
    {
        if(seq[i] == '(')
        {
            iMax++;
        }
        else
        {
            iMax--;
        }

        if(iMaxTotal < iMax)
        {
            iMaxTotal = iMax;
        }
    }
    len = i;

    iDepth = (0 == iMaxTotal%2)? iMaxTotal/2: iMaxTotal/2+1;

    int *piResult = (int *)malloc(len * sizeof(int));
    if(0 == piResult)
    {
        *returnSize = 0;
        return returnSize;
    }

    piResult[0] = 0;
    ileftFlag = 1;
    for(i=1; i<len; i++)
    {
        if(seq[i] == '(')
        {
            if(iDepth > ileftFlag)
            {
                piResult[i] = 0;
                ileftFlag++;
            }
            else
            {
                piResult[i] = 1;
                iRightFlag++;
            }
            // if(0 == iRightFlag)
            // {
            //     piResult[i] = 1;
            //     iRightFlag++;
            // }
            // else
            // {
            //     piResult[i] = 0;
            //     ileftFlag++;
            // }
        }
        else
        {
            if(0 != ileftFlag)
            {
                piResult[i] = 0;
                ileftFlag--;
            }
            else
            {
                piResult[i] = 1;
                iRightFlag--;
            }
        }
    }

    *returnSize = len;
    return piResult;
}
```