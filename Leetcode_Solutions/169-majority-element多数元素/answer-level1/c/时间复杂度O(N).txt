### 解题思路
绝大多数的数字出现次数大于其他所有数数字出现次数之和，那么假定一个数是绝大多数，遍历数组，出现一样的数字，次数++，否则--，当次数为0时，说明这个数字绝对不是绝大多数，改变结果，继续循环。

### 代码

```c
int majorityElement(int* nums, int numsSize){
    int i = 0;
    int ret = nums[0];
    int retNum = 1;
    for(int i=1;i<numsSize;i++){
        if(nums[i]!=ret){
            retNum -- ;
            if (retNum==0)
            {
                ret = nums[i];
                retNum++;
            }
        }
        else{
            retNum++;
        }
    }
    return ret;

}
```