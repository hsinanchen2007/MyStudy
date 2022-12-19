### 解题思路
此处撰写解题思路

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    int count=0;
    if(numsSize==0) return 0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=val){
            nums[count++]=nums[i];   //counts有着计数和作为“新”数组的插入点作用
        }
    }
    return count;
}
```