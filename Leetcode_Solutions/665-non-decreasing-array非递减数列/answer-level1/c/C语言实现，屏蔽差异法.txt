执行结果：通过
显示详情
执行用时 :24 ms, 在所有 C 提交中击败了99.13%的用户
内存消耗 :8.2 MB, 在所有 C 提交中击败了70.59%的用户

```

bool checkPossibility(int* nums, int numsSize){
    int flag = 0;
    int i = 0;
    int j = i + 1;
    int k[2] = {numsSize, numsSize};
    
    while (i < numsSize && j < numsSize) {
        if (nums[i] <= nums[j]) {
            ++i;
            ++j;
            continue;
        }
        flag = 1;
        k[0] = i;
        k[1] = j;
        break;
    }
    
    if (flag == 0) return true;
    flag = 0;
    for (int b = 0; b < 2; ++b) {
        i = 0;
        if (i == k[b]) ++i;
        j = i + 1;
        while (i < numsSize && j < numsSize) {
            if (i == k[b]) ++i;
            if (j == k[b]) ++j;
            if (j == numsSize) break;
            if (nums[i] <= nums[j]) {
                ++i;
                ++j;
                continue;
            }
            if (flag) return false;
            flag = 1;
            break;
        }
    }
        
    return true;
}
```
