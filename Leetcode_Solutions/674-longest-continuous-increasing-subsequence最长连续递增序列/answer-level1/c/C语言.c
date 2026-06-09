### 解题思路
此处撰写解题思路

### 代码

```c
int findLengthOfLCIS(int* nums, int numsSize){
    int count = 1,maxcount = 0;
    if(numsSize < 1)
        return 0;
    for(int i = 1;i<numsSize;i++){
        if(nums[i] >nums[i-1])
            count++;
        else {

            maxcount = (maxcount< count)? count:maxcount;
            count = 1;
        }
        if(nums[i] == nums[i-1]){
            count = 1;
        }
    }
    return (maxcount< count)? count:maxcount;
}
```