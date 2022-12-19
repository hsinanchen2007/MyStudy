### 解题思路
先从左往右遍历一次，记录一次位置。在从右往左遍历一次，记录位置，取小的。

### 代码

```php
class Solution {

    /**
     * @param String $S
     * @param String $C
     * @return Integer[]
     */
    function shortestToChar($S, $C) {
        $res = [];
        $pos = PHP_INT_MIN;
        for ($i = 0; $i < strlen($S); $i++) {
            if ($S[$i] == $C) $pos = $i;
            $res[$i] = $i - $pos;
        }

        $pos = PHP_INT_MAX;
        for ($i = strlen($S) - 1; $i >= 0; $i--) {
            if ($S[$i] == $C) $pos = $i;
            $res[$i] = min($res[$i], $pos - $i); 
        }

        return $res;
    }
}
```

### 算法复杂度
- 时间复杂度：O(n)
- 空间复杂度：O(n)

### 参考
[https://leetcode-cn.com/problems/shortest-distance-to-a-character/solution/zi-fu-de-zui-duan-ju-chi-by-leetcode/](https://leetcode-cn.com/problems/shortest-distance-to-a-character/solution/zi-fu-de-zui-duan-ju-chi-by-leetcode/)