击败90%C提交 

仅在当前值与其后第二位数值不相同时才会录入
可以理解为在出现多个相同数字的情况下
只会录入最后两个相同的数字。
在此循环中最后一位数字不会被录入 只参与比较 因此在循环结束后需要录入


### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    if(numsSize==0||numsSize==1||numsSize==2) return numsSize;
    int tmp=nums[0];
    int length=0;
    
    for(int i=1;i<numsSize-1;i++){
        if(tmp==nums[i+1]) continue;
        nums[++length]=nums[i];
        tmp=nums[i];
    }
    nums[++length]=nums[numsSize-1];
    return length+1;
}
```