### 解题思路
    动态规划的典型例题，和小偷盗劫为同一题，由于当前状态的获得只依赖之前的两个状态，所
以如果用变量代替数组可以使空间复杂度从O(n)降到O(1);

![1.png](https://pic.leetcode-cn.com/6dd88d558a720571b027a2494c703584de629c9ecdaea747fd09b9477dddb014-1.png)


### 代码

```java
class Solution {
    public int massage(int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        int N = nums.length;
        int res = 0;

        if(N == 1) return nums[0];
        if(N == 2) return Math.max(nums[0], nums[1]);

        int pre_b = nums[0];
        int pre_1 = nums[1];
        for(int i = 2;i < N; i++ ){
            res = Math.max(pre_b + nums[i], pre_1);
            pre_b = Math.max(pre_1,pre_b);
            pre_1 = res;
        }

        return res;
    }
}
```