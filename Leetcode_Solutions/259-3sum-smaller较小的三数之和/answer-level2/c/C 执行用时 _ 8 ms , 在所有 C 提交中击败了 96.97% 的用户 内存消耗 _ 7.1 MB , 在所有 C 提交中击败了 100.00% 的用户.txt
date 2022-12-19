```
int cmp(const void* a,const void* b) {
    return *(int*)a - *(int*)b;
}

int threeSumSmaller(int* nums, int numsSize, int target){
    qsort(nums,numsSize,sizeof(int),cmp);
    int count = 0;
    
    for(int i = 0;i < numsSize;i++) {
        int left = i+ 1;
        int right = numsSize - 1;
        
        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum >= target) {
                right--;
            } else {
                count = count + right - left;
                left++;
            }
        }
    }
    return count;
}
```
