### 解题思路
//num[i+1] > num[i],那么num[i+1]便是num[i]的下个更大值
//num[i+1] < num[i],先将num[i]入栈， 继续遍历nums



给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。

示例 1:

输入: [1,2,1]
输出: [2,-1,2]
解释: 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数； 
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
       int stack[10000][2] = {0};//malloc(numsSize * sizeof(int));
        int* res = malloc(numsSize * sizeof(int));
        int i, p = 0;

        for (i = 0; i < numsSize; i++) {
            if (p > 0) {
                //单调栈， 这里实现单调递增的
                //如果栈里有数，将小于当前值的全部出栈。 那么出栈的这些数下一个更大值就是当前nums[i]了
                while(p>0 && nums[i] > stack[p-1][1]){
                    p--;
                    res[stack[p][0]] = nums[i];
                }
            }  
            //num[i+1] > num[i],那么num[i+1]便是num[i]的下个更大值
            //num[i+1] < num[i],先将num[i]入栈， 继续遍历nums
            if (i< numsSize-1 && nums[i] < nums[i+1])
                res[i] = nums[i+1];
            else {
                res[i] = -1;
                stack[p][0] = i;
                stack[p++][1] = nums[i];
            }
        }

        i = 0;
        while (i < numsSize && p > 0) {
            while (p > 0 && nums[i] > stack[p - 1][1]) {
                p--;
                res[stack[p][0]] = nums[i];
            }
            i++;
        }

    *returnSize = numsSize;
    return res;
}
```