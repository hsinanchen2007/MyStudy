```
    public boolean splitArray(int[] nums) {
        if (nums.length < 7) {
            return false;
        }
        int n = nums.length;
        int firstRange = 0, forthRange;
        for (int i = 1; i < n - 3; i++) {
            if (nums[i] == 0 && nums[i - 1] == 0) {
                continue;
            }
            firstRange += nums[i - 1];
            int secRange = 0;
            for (int j = i + 2; j < n - 2; j++) {
                if (nums[j] == 0 && nums[j - 1] == 0) {
                    continue;
                }
                secRange += nums[j - 1];
                if (firstRange != secRange) {
                    continue;
                }
                int thirdRange = 0;
                for (int k = j + 2; k < n - 1; k++) {
                    thirdRange += nums[k - 1];
                    if (secRange != thirdRange) {
                        continue;
                    }
                    forthRange = Arrays.stream(nums).skip(k + 1).limit(n - k - 1).sum();
                    if (thirdRange == forthRange) {
                        System.out.println(i + "" + j + "" + k + "" + n);
                        return true;
                    }
                }
            }
        }
        return false;
    }
```


没想到什么特别好的分组方式。题目描述的数组是无序的无规律数组，似乎只能看做是要插三个隔板，求分开的四组是否相等
总体思路是暴力三个循环求解

具体针对case优化了几次，比如每轮循环之前就可以判断是否相等，减少轮次
然后被一个有1000多个0的case挂了。又优化了一下如果是连续的0就跳过

最终代码如上，
执行用时 :137 ms, 在所有 Java 提交中击败了75.76%的用户
内存消耗 :40.6 MB, 在所有 Java 提交中击败了100.00%的用户