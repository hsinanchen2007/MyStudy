### 解题思路
此处撰写解题思路

### 代码

```c
int findRepeatNumber(int* nums, int numsSize){
    int hashmap[numsSize];
    for(int i=0;i<numsSize;i++){
        hashmap[i] = 0;
    }
    for(int i=0;i<numsSize;i++){
        hashmap[nums[i]]++;
        if(hashmap[nums[i]] > 1){
            return nums[i];
        }
    }
    return 0;
}
```