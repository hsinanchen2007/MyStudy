### 解题思路
遍历枚举各种情况

### 性能
执行用时 :40 ms, 在所有 PHP 提交中击败了100.00%的用户
内存消耗 :16 MB, 在所有 PHP 提交中击败了28.57%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $bills
     * @return Boolean
     */
    function lemonadeChange($bills) {
        $five = $ten = 0;
        for ($i = 0; $i < count($bills); $i++) {
            if ($bills[$i] == 5) {
                $five++;
                continue;
            }

            if ($bills[$i] == 10) {
                if ($five > 0) {
                    $five--;
                    $ten++;
                }else {
                    return false;
                }
            } else {
                if ($five > 0 && $ten > 0) {
                    $five--;
                    $ten--;
                } elseif ($five >= 3) {
                    $five -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
}
```