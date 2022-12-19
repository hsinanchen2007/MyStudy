### 解题思路
若当前值的hash值已经加过1了，则直接返回。

### 代码

```c
int findRepeatNumber(int* nums, int numsSize){
    int *hash = (int *)calloc(numsSize, sizeof(int));
    for(int i = 0; i < numsSize; i++){
        if(hash[nums[i]] == 1){
            return nums[i];
        } else {
            hash[nums[i]]++;
        }
    }
    return -1;
}
```