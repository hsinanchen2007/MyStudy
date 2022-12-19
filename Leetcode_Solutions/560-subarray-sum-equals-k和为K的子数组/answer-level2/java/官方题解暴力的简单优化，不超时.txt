最简单的就是考虑nums的每一个可能的子数组，找到子数组的元素总和，并比较和给定k是否相等。当总和 和 k 相等时，进行计数。

优化点在于：没必要去遍历，直接在第二个循环中取累加就好了。这样时间复杂度降低了。
按照官方题解中的暴力会超时，但是按照我的暴力，可以通过。

建议大家学习其他更优解，比如哈希表。

```
class Solution {
    public int subarraySum(int[] nums, int k) {
        int num = 0;
        for (int i = 0; i < nums.length; i++) {
            int temp = 0;
            for (int j = i; j < nums.length; j++) {
                temp += nums[j];
                if (temp == k) {
                    num++;
                }
            }
        }
        return num;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int [] nums = {0,0,0,0,0,0,0,0,0,0};
        int k = 0;
        int ans = solution.subarraySum(nums, k);
        System.out.println(ans);
    }
}
```

复杂度分析
- 时间复杂度：O(n^2).
- 空间复杂度：O(1)



执行结果：
![image.png](https://pic.leetcode-cn.com/423ac06087d85a5f70c95fddbf2746c3b8b7442fd5d525276daa4f1e859411e8-image.png)




