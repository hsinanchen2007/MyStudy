### 解题思路
step1:找出可能是主要元素的数组元素，用变量count计数，变量res存可疑元素的值。遍历一次数组，期间碰到值相同的元素则count++，否则count--，当count减为0，可疑元素改变为下一个元素，重置count。遍历结束得到可疑元素res。
step2:对可疑元素进行验证，为此需要再遍历一次数组统计可疑元素实际个数(>=count)，根据计数结果是否过半返回相应值。

遍历两次数组，时间复杂度O(n)，使用两个变量，空间复杂度O(1)。
代码垃圾请见谅，欢迎指正。

### 代码

```c
int majorityElement(int* nums, int numsSize){
    int res = nums[0], count = 1;
    /*找出可疑元素*/
    for(int i = 1; i < numsSize; i++)
    {
        if(nums[i]==res)
        {
            count++;
            continue;
        }
        if(--count==0)
        {
            count = 1;
            res = nums[i];
        }                
    }
    /*无需验证直接返回*/
    if(count > numsSize / 2)
        return res;
    /*验证可疑元素*/
    count = 0;
    for(int i = 0; i < numsSize; i++)
        if(nums[i] == res)
            count++;
    if(count > numsSize / 2)
        return res;
    return -1;   
}
```