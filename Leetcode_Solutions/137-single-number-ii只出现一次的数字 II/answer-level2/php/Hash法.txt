### 解题思路
哈希实现

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function singleNumber($nums) {
        $maps = [];
        for ($i = 0; $i < count($nums); $i++) {
            $tmp = isset($maps[$nums[$i]]) ? $maps[$nums[$i]] : 0;
            $maps[$nums[$i]] = $tmp + 1;
        }

        foreach ($maps as $k => $v) {
            if ($v == 1) return $k;
        }
    }
}
```

### 性能
执行用时 :28 ms, 在所有 PHP 提交中击败了18.75%的用户
内存消耗 :17 MB, 在所有 PHP 提交中击败了55.56%的用户

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(N)