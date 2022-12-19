### 解题思路
题目要求原地移除元素，实际也就是将非val的元素移到数组前面的有效位置。设置两个指针分别为m和n,m用于遍历整个数组元素，而n用于指示最终返回数组非val值的位置。

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
   int count=numsSize,m=0,n=0;
   for(m=0;m<numsSize;m++){
       if(nums[m]!=val){
        nums[n]=nums[m];
        n++;   
       } 
       else count--;
   }
    return count;
}
```