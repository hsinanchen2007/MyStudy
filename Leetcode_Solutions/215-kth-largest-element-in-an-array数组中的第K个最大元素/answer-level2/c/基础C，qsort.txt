### 解题思路
先用C自带快排qsort，再找到对应元素即可；

### 代码

```c

int comp(int* a,int* b){
    return (*a)>(*b)?1:0;
}

int findKthLargest(int* nums, int numsSize, int k)
{
    int i,j=0;
    qsort(nums,numsSize,sizeof(int),comp);
    return nums[numsSize-k];
}
```