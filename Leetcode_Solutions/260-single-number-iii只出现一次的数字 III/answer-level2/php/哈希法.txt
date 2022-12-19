### 解题思路
哈希法

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function singleNumber($nums) {
        $maps = [];
        foreach ($nums as $num) {
            $tmp = isset($maps[$num]) ? $maps[$num] : 0;
            $maps[$num] = $tmp + 1;
        }

        $res = [];
        foreach ($maps as $num => $count) {
            if ($count == 1) $res[] = $num;
        }

        return $res;
    }
}
```

### 性能
执行用时 :24 ms, 在所有 PHP 提交中击败了36.84%的用户
内存消耗 :17.1 MB, 在所有 PHP 提交中击败了33.33%的用户

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(N)