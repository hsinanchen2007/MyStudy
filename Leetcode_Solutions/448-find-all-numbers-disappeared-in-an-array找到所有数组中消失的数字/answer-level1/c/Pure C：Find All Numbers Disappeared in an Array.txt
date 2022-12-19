## solution:
① 使用**index** = Nums\[i]-1   
							Nums\[index] 发生变化，      (第一个代码变化为取反，第二个代码变化为+n)
②  遍历：在数组中没有变化的即没有出现的。
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    for(int i=0;i<numsSize;i++){
        int index = abs(nums[i])-1;
        nums[index] =-abs(nums[index]);
    }
    int *Return = (int*)malloc(sizeof(int)*numsSize);
    int Len = 0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]>0)
            Return[Len++] = i+1;
    }
    *returnSize = Len;
    return Return;
}
```

```


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    for(int i=0;i<numsSize;i++){
        int index = (nums[i]-1)%numsSize;
        nums[index] +=numsSize;
    }
    int *ReturnArray = (int*)malloc(sizeof(int)*numsSize);
    int Len = 0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]<=numsSize)
           ReturnArray[Len++] = i+1; 
    }
    *returnSize = Len;
    return ReturnArray;
}
```