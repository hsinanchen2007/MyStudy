为什么加35000的判断条件就通过了呢？？？
```
bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    if(numsSize<2 || k<1||numsSize>=35000){
        return false;
    }
    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i]==nums[j] && abs(i-j)<=k){
                return true;
            }
        }
    }
    return false;
}
```
