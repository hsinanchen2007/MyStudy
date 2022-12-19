### 解题思路

### 性能
执行用时 :16 ms, 在所有 PHP 提交中击败了89.84%的用户
内存消耗 :16.9 MB, 在所有 PHP 提交中击败了27.69%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $prices
     * @return Integer
     */
    function maxProfit($prices) {
        $max_profix = 0;
        if (empty($prices)) return $max_profix;

        $min_price = $prices[0];
        for ($i = 1; $i < count($prices); $i++) {
            $min_price = min($min_price, $prices[$i]);
            $max_profix = max($max_profix, $prices[$i] - $min_price);
        }
        
        return $max_profix;
    }
}
```

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(1)

### 参考