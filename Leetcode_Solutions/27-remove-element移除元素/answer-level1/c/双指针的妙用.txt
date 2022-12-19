### 解题思路
通过借助双指针，一慢一快两个指针优雅地处理该问题。

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
int i=0,j;
for(j=0;j<numsSize;j++){
    if(nums[j]!=val){
        nums[i]=nums[j];
        i++;
    }
}
return i;
}
```