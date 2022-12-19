### 解题思路
看大家用的都是找规律的方法，这里就暴力破解了，性能果然很暴力，哈哈哈。

### 性能
执行用时 :36 ms, 在所有 php 提交中击败了5.75%的用户
内存消耗 :15.1 MB, 在所有 php 提交中击败了5.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer $num
     * @return Integer
     */
    function addDigits($num) {
        while ($num > 9) {
            $sum = 0;
            while ($num) {
                $sum += $num % 10;
                $num = $num / 10;
            }

            $num = $sum;
        }

        return $num;
    }
}
```