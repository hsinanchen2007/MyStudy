C语言 模拟哈希hashCount表示左边有i个奇数的位置的个数
```

int numberOfSubarrays(int* nums, int numsSize, int k){
    int* hashCount = (int*)malloc(sizeof(int) * (numsSize + 1));
    memset(hashCount, 0 , sizeof(int) * (numsSize + 1));
    int ans = 0;
    hashCount[0] = 1;
    int count = 0;
    for (int i = 1; i <= numsSize; i++) {
        int target;
        if (nums[i - 1] % 2 == 1) {
            count++;
        }
        hashCount[count]++;
        target = count - k;
        if (target >= 0) {
            ans += hashCount[target];
        }
    }
    return ans;
}
```
