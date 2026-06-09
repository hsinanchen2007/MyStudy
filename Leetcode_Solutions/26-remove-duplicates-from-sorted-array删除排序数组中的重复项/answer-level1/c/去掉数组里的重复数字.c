### 解题思路
此处撰写解题思路

### 代码

```c
int removeDuplicates(int* nums, int numsSize){
 int h=0,q=1;
 if(numsSize==0) return 0;
for(q=1;q<numsSize;q++){
    if(nums[h]!=nums[q]){
        h++;
        nums[h]=nums[q];
    }
}
 return h+1;
}
```