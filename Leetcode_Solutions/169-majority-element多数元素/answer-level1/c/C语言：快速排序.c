![求众数.png](https://pic.leetcode-cn.com/d972ed06eb034994b4be3e3ced40f334fda96776eeb5f37ebd4b20dc9f203654-%E6%B1%82%E4%BC%97%E6%95%B0.png)
```

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
int majorityElement(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    int cnt = 1;
    for (int i = 1; i < numsSize; i++){
        if (nums[i] == nums[i - 1])
            cnt++;
        if (cnt > numsSize / 2)
            return nums[i];
        if (nums[i] != nums[i - 1])
            cnt = 1;
    }
    return nums[0];//the array only has one number.
}


```
