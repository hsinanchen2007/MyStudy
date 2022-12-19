### 解题思路
类似的快慢指针思想
### 代码

```c

// 双指针
// 原地修改数组
void moveZeroes(int* nums, int numsSize){
    int i, not_zero = 0;         // 非零元素index
    for ( i = 0; i < numsSize; i++ ) {
        if ( nums[i] != 0 ) {
            nums[not_zero++] = nums[i];
        }
    }
    
    // 后面补0
    while ( numsSize-not_zero > 0 ) {
        nums[not_zero++] = 0;
    }

}


```