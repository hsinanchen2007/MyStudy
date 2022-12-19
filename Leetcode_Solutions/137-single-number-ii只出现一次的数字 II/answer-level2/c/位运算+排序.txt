### 解题思路
先用qsort排序，然后异或运算。
### 代码

```c
int comFun(const void *a, const void *b) 
{
    if( *(int*)a > *(int*)b){
        return 1;
    } else {
        return 0;
    }
}
int singleNumber(int* nums, int numsSize){
    if(numsSize == 0) {
        return 0;
    }
    if(numsSize <= 3) {
        return nums[0];
    }
    qsort(nums, numsSize, sizeof(int), comFun);
    int i = 0;
    int tmp = 0;
    while(i < (numsSize-2)) {
        tmp = nums[i]^nums[i+1];
        if(tmp == 0 && nums[i+1] == nums[i+2]) {
            i += 3;
            continue;
        }
        if (tmp != 0) {
            tmp = nums[i];
            break;
        }
    }
    if(i == numsSize - 1) {
        tmp = nums[numsSize - 1];
    }
    return tmp;
}
```