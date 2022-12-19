### 解题思路
1、定义3个变量，索引、左值之和、右值之和；
2、索引初始赋值为1，左值初始赋值为0，右值初始赋值为nums[1] 到 nums[numsSize - 1]之和；
3、遍历数组范围，每次遍历，左值加索引左边的数值，右值减索引所在的数值，判断左值和右值是否相等，相等则返回索引；
4、注意：需要额外判断索引为0和numsSize - 1的情况。

### 代码

```c
int pivotIndex(int* nums, int numsSize){
    int left  = 0;
    int right = 0;
    int index;
    
    if (numsSize < 3) {
        return -1;
    }
    
    for (index = 1; index < numsSize; index++) {
        right = right + nums[index];
    }
    
    if (right == 0) {
        return 0;
    }
    
    for (index = 1; index < numsSize - 1; index++) {
        left = left + nums[index - 1];
        right = right - nums[index];
        if (left == right) {
            return index;
        }
    }

    if (left + nums[index - 1] == 0) {
        return index;
    }
    
    return -1;
}
```