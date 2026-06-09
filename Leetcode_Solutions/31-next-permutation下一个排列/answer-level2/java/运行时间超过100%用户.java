java语言，运行时间超过100%用户
```
public void nextPermutation(int[] nums) {
    boolean haveNext = true;
    for (int i = 0; i < nums.length - 1; i++){
        if (nums[i] < nums[i + 1]){
            haveNext = false;
            break;
        }
    }
    if (haveNext){
        for (int i = 0; i < nums.length / 2; i++){
            int a = nums[i];
            nums[i] = nums[nums.length - i - 1];
            nums[nums.length - i - 1] = a;
        }
        return;
    }

    int start = nums.length - 2;
    while (!check(nums, start) && start >= 0){
        start--;
    }
    if (start == -1){
        start = 0;
    }

    int end = findMin(nums, start);

    exchange(nums, start, end);
}

public int[] exchange(int[] nums, int n, int m){
    int tmp = nums[m];
    for (int i = m; i > n ; i--){
        nums[i] = nums[i - 1];
    }
    nums[n] = tmp;
    Arrays.sort(nums, n+1, nums.length);
    return nums;
}

// n 后面的数字存在大于nums[n]， 返回true；
public boolean check(int[] nums, int n){
    for (int j = n + 1; j < nums.length; j++){
        if (nums[n] < nums[j]){
            return true;
        }
    }
    return false;
}

// 发现n后大于nums[n]的最小的一个数，取靠后的
public int findMin(int[] nums, int n){
    int res = nums.length - 1;
    while (nums[res] <= nums[n]){
        res--;
    }
    for (int i = res - 1; i > n; i--){
        if (nums[res] > nums[i] && nums[i] > nums[n]){
            res = i;
        }
    }
    return res;
}
```