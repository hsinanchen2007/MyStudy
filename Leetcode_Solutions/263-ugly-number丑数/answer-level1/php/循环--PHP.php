### 解题思路


### 性能
执行用时 :12 ms, 在所有 php 提交中击败了45.16%的用户
内存消耗 :15 MB, 在所有 php 提交中击败了14.29%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer $num
     * @return Boolean
     */
    function isUgly($num) {
        if ($num < 1) {
            return false;
        }

        while ($num != 1) {
            if ($num % 2 == 0) {
                $num /= 2;
            } elseif ($num % 3 == 0) {
                $num /= 3;
            } elseif ($num % 5 == 0) {
                $num /= 5;
            } else {
                return false;
            }
        }

        return true;
    }
}
```