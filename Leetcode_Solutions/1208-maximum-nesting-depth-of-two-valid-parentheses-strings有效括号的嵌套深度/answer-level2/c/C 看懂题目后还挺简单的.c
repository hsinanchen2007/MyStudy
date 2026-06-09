### 解题思路
看题目看了3遍才看懂，也是开始怀疑自己了，看懂后就觉得还行，解法如下：
1、首先如果字符串长度是奇数或者第一位是')'或者最后一位是'('，那么肯定不满足要求；
2、然后申请一个数组保存返回值，字符串第一位一定是'('，所以数组第一位就先赋值0，也就是分到A里面，之后字符串一位一位的比过去，如果字符串当前位与前一位相同那么就放到另一个子字符串里面，不等的话就还放到当前子字符串。
（比如第一位是'('，先放到A里面了，返回数组res[0]=0，第二位如果还是'('，那么就放到B里面，返回数组里面这个下标的值就赋与前一个的相反数res[1]=1;相反第二位如果是')'，那么就还放到A里面，返回数组里面这个下标的值就赋与前一个的相同数res[1]=0）
3、一直遍历结束就好

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char * seq, int* returnSize)
{
    int len = strlen(seq);
    if(len % 2 == 1 || seq[0] == ')' || seq[len - 1] == '(')
    {
        return 0;
    }
    * returnSize = len;

    int status = 0;
    int * res = (int *)malloc(len * sizeof(int));
    res[0] = 0;
    for(int i = 1; i < len; i++)
    {
        if(seq[i] != seq[i -1])
        {
            res[i] = res[i-1];
        }
        else
        {
            res[i] = !res[i-1];
        }
    }
    return res;

}
```