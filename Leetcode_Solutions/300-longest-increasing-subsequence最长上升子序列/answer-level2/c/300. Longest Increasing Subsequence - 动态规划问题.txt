### 解题思路
建立一个数组来存放每个元素的最长值,初始化的序列长度初始化为1.
对每个元素i,向前查找当前的最长序列长度.
如果存在某个元素j满足"dpi<dpj+1"
那就说明i前面存在一个序列,满足长度和更大.
返回dp数组里面的最大值即可.

### 代码

```c
int lengthOfLIS(int* nums, int numsSize)
{
    // 如果数组长度为0,则直接返回0
    if(numsSize == 0) return 0;
    // 建立一个数组用来存储所有的元素的最长序列长度
    int dp[numsSize];
    int max=1, i, j;
    // 对dp数组进行初始化操作
    for(i=0; i<numsSize; i++) dp[i] = 1;
    // 注意此处是从i=1开始的,即数组的第二个位置开始的
    for(i=1; i<numsSize; i++)
    {
        // j是从0开始的,因为对于i要从前面所有的开始判断到i
        for(j=0; j<i; j++)
        {
            // 如果i大于j,说明前面有比i小的元素序列
            // 对于这个j需要满足什么呢?
            // 需要满足这个dpj+1(j序列向后补充一位i)必须大于dpi,否则这个最长就没有意义了
            if(nums[i]>nums[j] && dp[j]+1>dp[i])
            {   
                //更新dpi
                dp[i] = dp[j]+1;
                if(dp[i]>max) max =dp[i];
            }
        }
    }
    return max;
}
```