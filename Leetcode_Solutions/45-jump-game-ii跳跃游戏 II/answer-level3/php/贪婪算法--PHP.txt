### 解题思路
贪婪算法，每一步都跳能跳范围最大的，画图很容易理解。

**注意：最后一个元素不用遍历到，因为第一个已经加1了。**

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function jump($nums) {
        $count = 0;
        $end = 0;
        $max_pos = 0;
        for ($i = 0; $i < count($nums) - 1; $i++) {
            $max_pos = max($max_pos, $nums[$i] + $i);
            if ($end == $i) {
                $end = $max_pos;
                $count++;
            }
        }

        return $count;
    }
}
```

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(1)

### 参考
[https://leetcode-cn.com/problems/jump-game-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-10/](https://leetcode-cn.com/problems/jump-game-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-10/)