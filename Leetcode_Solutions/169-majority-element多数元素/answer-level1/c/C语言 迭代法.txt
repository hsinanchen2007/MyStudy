###题解
    最基础的解法，数组拍完序后依次遍历，遇到一样的数后count加1，不一样count重新清1，count大于N/2后就return

###代码
```
int cmp(const void* a,const void* b){
    if(*(int*)a>*(int*)b){
        return 1;
    }else if(*(int*)a<*(int*)b){
        return -1;
    }else{
        return 0;
    }
}

int majorityElement(int* nums, int numsSize){
    int count = 1;
    qsort(nums,numsSize,sizeof(int),cmp);
    
    for(int i=0;i<numsSize;++i){
        if(i+1<numsSize&&nums[i+1]==nums[i]){
            count++;
        }else{
            count = 1;
        }
        if(count>numsSize/2){
            return nums[i];
        }
    }
    return 0;
}
```

