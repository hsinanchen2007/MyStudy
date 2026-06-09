### 解题思路
动态规划

算法：
- 状态dp_max[i]表示到第i个元素最大乘积，dp_min[i]表示到第i个元素最小乘积
- 状态转移方程
dp_max[i] = max(nums[i], dp_max[i - 1] * nums[i], dp_min(i - 1) * nums[i]);
dp_min[i] = max(nums[i], dp_max[i - 1] * nums[i], dp_min(i - 1) * nums[i]);
- 初始化
dp_max[0] = dp_min[0] = nums[0]
- 最大值max需要单独记录，并不是dp_max[count(nums) - 1]

## 解法一
标准的动态规划

### 代码
```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function maxProduct($nums) {
        if (empty($nums)) return 0;

        $dp_max = $dp_min = [];

        $dp_max[0] = $dp_min[0] = $nums[0];

        $max = $nums[0];

        for ($i = 1; $i < count($nums); $i++) {
            $dp_max[$i] = max($nums[$i], $dp_max[$i - 1] * $nums[$i], $dp_min[$i - 1] * $nums[$i]);
            $dp_min[$i] = min($nums[$i], $dp_max[$i - 1] * $nums[$i], $dp_min[$i - 1] * $nums[$i]);

            $max = max($max, $dp_max[$i]);
        }

        return $max;
    }
}
```

### 性能
执行用时 :12 ms, 在所有 PHP 提交中击败了88.00%的用户
内存消耗 :16.6 MB, 在所有 PHP 提交中击败了28.95%的用户

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(N)

### 参考
[https://leetcode-cn.com/problems/maximum-product-subarray/solution/js-dong-tai-gui-hua-by-stack_pop-2/](https://leetcode-cn.com/problems/maximum-product-subarray/solution/js-dong-tai-gui-hua-by-stack_pop-2/)


## 解法二
简化的动态规划。看起来很简单，似乎也很容易理解，但似乎有似懂非懂，如果没有彻底理解动态规划。


### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function maxProduct($nums) {
        $max = PHP_INT_MIN;
        $sub_max = $sub_min = 1;
        
        for ($i = 0; $i < count($nums); $i++) {
            if ($nums[$i] < 0) {
                $sub_max = $sub_max ^ $sub_min;
                $sub_min = $sub_max ^ $sub_min;
                $sub_max = $sub_max ^ $sub_min;
            }

            $sub_max = max($sub_max * $nums[$i], $nums[$i]);
            $sub_min = min($sub_min * $nums[$i], $nums[$i]);

            $max = max($max, $sub_max);
        }

        return $max;
    }
}
```

### 性能
执行用时 :28 ms, 在所有 PHP 提交中击败了14.00%的用户
内存消耗 :16.1 MB, 在所有 PHP 提交中击败了44.74%的用户

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(1)

### 参考
[https://leetcode-cn.com/problems/maximum-product-subarray/solution/hua-jie-suan-fa-152-cheng-ji-zui-da-zi-xu-lie-by-g/](https://leetcode-cn.com/problems/maximum-product-subarray/solution/hua-jie-suan-fa-152-cheng-ji-zui-da-zi-xu-lie-by-g/)