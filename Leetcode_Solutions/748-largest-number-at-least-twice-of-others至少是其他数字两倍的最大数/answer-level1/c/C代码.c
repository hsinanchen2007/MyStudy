### 解题思路
先找出数组中的最大值的索引，因为比数组中其他每个数大至少两倍，那这个数肯定是整个数组的最大值。 接着遍历整个数组，进行判断，如果数组的最大值没有大于其他数超过二倍，则返回-1。 
为什么不用除法进行判断，比如说nums[indexMax] / nums[i] > 2 这是因为考虑到除数不能为0。 
为什么要indexMax != i ，因为不能把自己也纳入遍历的范围内，自己肯定小于自己的二倍，铁定返回-1了。

### 代码

```c
int dominantIndex(int* nums, int numsSize){

    int indexMax = 0;

    for(int i = 0; i < numsSize; i++){

        if(nums[i] > nums[indexMax]){

            indexMax = i;
        }
    }

    for(int i = 0; i < numsSize; i++){

        if(indexMax != i && nums[indexMax] < nums[i] * 2){

            return -1;
        }
    }
    
    return indexMax;
}
```