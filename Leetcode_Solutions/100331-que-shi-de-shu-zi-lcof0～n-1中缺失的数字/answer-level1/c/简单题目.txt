### 解题思路
此处撰写解题思路

### 代码

```c

int comparearry(const void *a, const void * b)
{
    int *aa = (int *)a;
    int *bb = (int *)b;
    return *aa - *bb;
}

int missingNumber(int* nums, int numsSize){

qsort(nums,numsSize,sizeof(int),comparearry);

if(nums[0] != 0) {
    return 0;
}

for(int i = 1; i < numsSize; i++) {
   if(nums[i] != nums[i-1] + 1) {
       return nums[i-1]+1;
   }
}
return numsSize;

}
```