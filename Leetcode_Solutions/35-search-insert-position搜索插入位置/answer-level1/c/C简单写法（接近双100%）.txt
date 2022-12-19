```
int searchInsert(int* nums, int numsSize, int target){
    if(target<=*(nums)||numsSize==0)
        return 0;
    for(int i=0;i+1<numsSize;i++)
        if(*(nums+i)<target&&target<=*(nums+i+1))
            return i+1;
    return numsSize;
}
```

