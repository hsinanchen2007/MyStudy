### 解题思路
遍历宝石💎，把宝石存在map中，遍历石头，检查是否在map中，在的话计数器增加。

### 代码

```php
class Solution {

    /**
     * @param String $J
     * @param String $S
     * @return Integer
     */
    function numJewelsInStones($J, $S) {
        $map = [];
        for ($i = 0; $i < strlen($J); $i++) {
            $map[] = $J[$i];
        }

        $count = 0;
        for ($j = 0; $j < strlen($S); $j++) {
            if (in_array($S[$j], $map)) $count++;
        }

        return $count;
    }
}
```

### 复杂度分析
- 时间复杂度：O(n) [n = strlen($J) + strlen($S)]
- 空间复杂度: O(n) [n = strlen($J)]