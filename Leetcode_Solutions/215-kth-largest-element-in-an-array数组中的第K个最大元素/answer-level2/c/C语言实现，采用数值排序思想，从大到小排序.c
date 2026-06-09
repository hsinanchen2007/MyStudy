```
// 取最大最小值，采用数值排序算法，起始值为max，终止值为min
int findKthLargest(int nums, int numsSize, int k) {
    int *numCount = NULL;
    int i, count, max, min;
    int ans = 0;
    max = nums[0];
    min = nums[0];
    
    for (i = 1; i < numsSize; i++) {
        max = (max > nums[i])? max:nums[i];
        min = (min < nums[i])? min:nums[i];
    }
    
    numCount = (int *)malloc(sizeof(int)*(max-min+1));
    memset(numCount, 0, sizeof(int)*(max-min+1));
    // printf("max:%d-min:%d", max, min);
    for (i = 0; i < numsSize; i++) {
        numCount[nums[i] - min]++;
    }
    count = 0;
    for (i = (max-min); i >= 0; i--) {
        count += numCount[i];
        if (count >= k) {
            ans = (i+min);
            break;
        }        
    }
    free(numCount);
    return ans;
}
```

