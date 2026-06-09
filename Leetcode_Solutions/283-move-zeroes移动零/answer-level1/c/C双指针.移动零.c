思路1：快慢指针移动：使用快指针i作为下标来遍历数组，将非0元素移动到数组前方，使用慢指针j作为下标来记录非零元素的位置；遍历结束后，对慢指针j之后的元素统一设置为0。
代码：
```
void moveZeroes(int* nums, int numsSize){
    int j = 0;//nozero value index
    
    if (numsSize == 0 || (nums == NULL)){
        return;
    }

    for (int i = 0; i < numsSize; ++i){
        if (nums[i] != 0){
            nums[j] = nums[i];
            j++;
        }
    }
    for (int i = j; i < numsSize; ++i){
        nums[i] = 0;
    }
}
```

思路2：双指针替换0：定义两个指针i,j,然后遍历数组，i，j同时前进，若遇到元素0时j停下，i继续前行。当元素nums[i]不为0时则将num[i]赋给num[j]，此时j++前行一步,此时nums[i]怎么办呢？我们知道nums[i]最终要么为零，要么非零；非零的话会通过上面的步骤迭代掉，零的话直接赋值0，所以这里nums[i]先被赋值为0；在i等于j的情况下，如果num[i]不为0，将num[i]赋给num[j]其实就是自己赋值给自己，无必要，所以可以加一个判断条件，i不等j的时候才替换0。
代码：
```
void moveZeroes(int* nums, int numsSize){
    int j = 0;//nozero value index
    
    if (numsSize == 0 || (nums == NULL)){
        return;
    }

    for (int i = 0; i < numsSize; ++i){
        if (nums[i] != 0){
            if (i != j){
                nums[j] = nums[i];
                nums[i] = 0;
            }
            j++;
        }
    }
} 
```