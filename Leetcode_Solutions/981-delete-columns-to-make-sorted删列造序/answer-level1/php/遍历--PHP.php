### 解题思路
- 看那一列不是生序的，就计数

### 性能
- 执行用时 :72 ms, 在所有 PHP 提交中击败了93.10%的用户
- 内存消耗 :16.4 MB, 在所有 PHP 提交中击败了82.14%的用户

### 代码

```php
class Solution {

    /**
     * @param String[] $A
     * @return Integer
     */
    function minDeletionSize($A) {
        $count = 0;
        for ($i = 0; $i < strlen($A[0]); $i++) {
            for ($j = 0; $j < count($A) - 1; $j++) {
                if ($A[$j][$i] > $A[$j + 1][$i]) {
                    $count++;
                    break;
                }
            }
        }

        return $count;
    }
}
```