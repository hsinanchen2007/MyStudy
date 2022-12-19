### 解题思路
动态规划。
在198的基础上，分两种情况考虑，取大者
一、打劫第一个房间
二、不打第一个房间

算法通198参考: [动态规划-数组不连续取数问题](https://leetcode-cn.com/problems/house-robber/solution/dong-tai-gui-hua-shu-zu-bu-lian-xu-qu-shu-wen-ti-b/)

注意：只有一间房的情况，需要单独处理。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function rob($nums) {
        if (count($nums) == 1) return $nums[0];
        
        return max($this->task(array_slice($nums, 0, count($nums) - 1)), $this->task(array_slice($nums, 1)));
    }

    public function task($nums)
    {
        if (empty($nums)) return 0;

        $dp[0] = $nums[0];
        $dp[1] = max($nums[0], $nums[1]);

        for ($i = 2; $i < count($nums); $i++) {
            $dp[$i] = max($dp[$i - 1], $dp[$i - 2] + $nums[$i]);
        }

        return array_pop($dp);
    }
}
```

### 性能
执行用时 :8 ms, 在所有 PHP 提交中击败了43.75%的用户
内存消耗 :15.3 MB, 在所有 PHP 提交中击败了22.22%的用户

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(N)

### 参考
[https://leetcode-cn.com/problems/house-robber-ii/solution/213-da-jia-jie-she-iidong-tai-gui-hua-jie-gou-hua-/](https://leetcode-cn.com/problems/house-robber-ii/solution/213-da-jia-jie-she-iidong-tai-gui-hua-jie-gou-hua-/)