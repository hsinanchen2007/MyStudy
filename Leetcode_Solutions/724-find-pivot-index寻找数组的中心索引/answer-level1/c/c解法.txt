### 解题思路
朴素的暴力解法，如果i索引左右两边和相同，那么加上i索引的和也一定相同，从左到右遍历比对查找即可。要注意每次如果没找到，右边的和要清零，左边的和则持续累加。
执行结果：
通过
显示详情
执行用时 :
880 ms
, 在所有 c 提交中击败了
23.52%
的用户
内存消耗 :
7.8 MB
, 在所有 c 提交中击败了
78.72%
的用户

### 代码

```c
int pivotIndex(int* nums, int numsSize)
{
    int i;
    int j;
    int sum1 = 0;
    int sum2 = 0;
    
    for (i = 0; i < numsSize; i++) {
        sum1 += nums[i];
        for (j = i; j < numsSize; j++) {
            sum2 += nums[j];
        }
        
        if (sum1 == sum2) {
            return i;            
        }  

        sum2 = 0;
    }

    return -1;
}
```