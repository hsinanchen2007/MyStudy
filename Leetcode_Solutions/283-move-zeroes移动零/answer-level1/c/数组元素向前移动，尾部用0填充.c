### 解题思路
用一个计数器统计为0的元素个数，每个元素前有多少个0就向前移动多少位，最后尾部用0替换。

### 代码

```c
void moveZeroes(int* nums, int numsSize){
    int count = 0;
    for(int i=0; i<numsSize; i++){
        nums[i-count]=nums[i];
        if(nums[i]==0)
            count++;
    }
    for(int j=numsSize-1; j>numsSize-count-1; j--)
        nums[j] = 0;
}
```