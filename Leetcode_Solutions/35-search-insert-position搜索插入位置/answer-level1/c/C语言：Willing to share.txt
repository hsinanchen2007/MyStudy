方法1：二分查找

```
int searchInsert(int* nums, int numsSize, int target){
    int l = 0, r = numsSize - 1, m;

    while (l <= r){
        m = (l + r) / 2;
        if (nums[m] < target)
            l = m + 1;
        else if (nums[m] > target)
            r = m - 1;
        else
            return m;
    }
    return l;
}

```

方法2：双指针

```
int searchInsert(int* nums, int numsSize, int target){
    int l = 0, r = numsSize - 1;
    while (l <= r){
        if (nums[l] < target)
            l++;
        else if (nums[l] == target)
            return l; 
        if (nums[r] > target)
            r--;
        else if (nums[r] == target)
            return r;
    }
    return l;
}
```
方法3：直接遍历

```
int searchInsert(int* nums, int numsSize, int target){
    for (int i = 0; i < numsSize; i++){
        if (nums[i] >= target)
            return i;
    }
    return numsSize;
}
```

```
int searchInsert(int* nums, int numsSize, int target){
    int i;
    if (numsSize == 0 || nums == NULL || target <= nums[0])
        return 0;
    for (i = 1; i < numsSize; i++){
        if ((target > nums[i - 1] && target < nums[i]) || target == nums[i])
            break;
    }
    return i;
}

```


