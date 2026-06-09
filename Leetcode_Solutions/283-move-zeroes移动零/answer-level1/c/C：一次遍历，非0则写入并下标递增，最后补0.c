理由：
遍历，元素非0就写到当前下标对应的位置，下标+1，
遍历结束后从当前下标开始补0到原数组长度
```
void moveZeroes(int* nums, int numsSize){
    int count = 0;
    int i = 0;
    for(i = 0; i < numsSize; i++) {
        if(nums[i] != 0){
            nums[count] = nums[i];
            count++;
        }
    }
    for(i = count; i < numsSize; i++){
        nums[i] = 0;
    }
}
```
