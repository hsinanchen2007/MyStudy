### 解题思路
此处撰写解题思路
原地建表
### 代码

```c
int removeElement(int* nums, int numsSize, int val){
     int i=0,len=-1;
     if(numsSize!=0){
         for(i=0;i<numsSize;i++){
             if(nums[i]!=val)
                nums[++len]=nums[i];
        }
     }
     len++;
     return len;
}
```