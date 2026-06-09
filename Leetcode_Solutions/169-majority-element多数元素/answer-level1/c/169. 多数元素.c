### 解题思路
可以理解为元素对抗，任意两个不同的元素相互消灭，剩下的元素即为多数元素。
时间复杂度O(n)。
具体：遍历所有元素，当前元素和临时结果一样时，cnt++；
不一样时，若cnt>1,cnt--;否则更新临时结果，cnt置1。

### 代码

```c
int majorityElement(int* nums, int numsSize){

    int cnt = 0;
    int ret = nums[0];
    for(int i = 0; i < numsSize; i++)
    {
        if(ret == nums[i])
            cnt++;
        else
        {
            if(cnt <= 1)
            {
                ret = nums[i];
                cnt = 1;
            }
            else
            {
                cnt--;
            }
        }
        if(cnt > numsSize/2)
            break;
    }
    return ret;
}
```