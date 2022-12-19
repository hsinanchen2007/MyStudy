# 标题 异或
有些类似于一个数组中只有1个数出现1次，其余都出现2次那道题。
时间复杂度肯定没有二分查找好。
```
// 异或
    public int missingNumber(int[] nums) {
        int len = nums.length;
        int res = nums[0];
        for(int i = 1; i < len; i++){
            res ^= nums[i];
        }
        for(int i = 0 ; i <= len; i++){
            res ^= i;
        }
        return res;
    }
```
