基于快速排序中分区函数的思想：

令pivot为0，将不等于0的元素都放到0的左边。代码实现：

```
 void moveZeroes(int* nums, int numsSize){
    if(numsSize == 0) {
        return;
    }
    
    int i = 0;
    for(int j = 0; j < numsSize; ++j) {
        if(nums[j] != 0) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            ++i;
        }
    }

}
```