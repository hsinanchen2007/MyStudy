```
int findDuplicate(int* nums, int numsSize){
    int a[100000]={0};
    for(int i=0;i<numsSize;i++){
        a[nums[i]]++;
        if(a[nums[i]]==2)
            return nums[i];
    }
    return 0;
}
```
