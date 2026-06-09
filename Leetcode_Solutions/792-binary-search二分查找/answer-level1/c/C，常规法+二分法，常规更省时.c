### 解题思路
常规法36ms，二分法80ms

### 代码
```
int search(int* nums, int numsSize, int target){
    int l=0,r=numsSize-1,m;
    while(l<=r){
        m=(l+r)/2;
        if(nums[m]>target)
            r=m-1;
        else if(nums[m]<target)
            l=m+1;
        else
            break;
    }
    return target==nums[m]?m:-1;
}
```

```c
int search(int* nums, int numsSize, int target){
    int i=0;
    for(;i<numsSize;i++)
        if(nums[i]==target)
            break;
    return i==numsSize?-1:i;
}
```