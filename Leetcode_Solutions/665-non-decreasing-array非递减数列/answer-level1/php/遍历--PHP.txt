### 解题思路
算法参考：[评论区](https://leetcode-cn.com/problems/non-decreasing-array/comments/11955)

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Boolean
     */
    function checkPossibility($nums) {
        $count = 0;
        if ($nums[0] > $nums[1]) {
            $count++;
            $nums[0] = $nums[1];
        }
        for ($i = 1; $i < count($nums) - 1; $i++) {
            if ($nums[$i] > $nums[$i + 1]) {
                $count++;
                if ($count > 1) return false;

                if ($nums[$i - 1] > $nums[$i + 1]) {
                    $nums[$i + 1] = $nums[$i];
                } else {
                    $nums[$i] = $nums[$i - 1];
                }
            }
        }

        return true;
    }
}
```

### 参考
[https://leetcode-cn.com/problems/non-decreasing-array/comments/11955](https://leetcode-cn.com/problems/non-decreasing-array/comments/11955)