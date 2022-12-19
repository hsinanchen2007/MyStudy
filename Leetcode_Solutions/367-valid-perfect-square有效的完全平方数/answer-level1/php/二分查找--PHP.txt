### 解题思路
典型的二分查找题目，注意1的情况。

### 代码

```php
class Solution {

    /**
     * @param Integer $num
     * @return Boolean
     */
    function isPerfectSquare($num) {
        if ($num == 1) {
            return true;
        }
        $front = 0;
        $rear = $num - 1;
        while ($front <= $rear) {
            $mid = intval(($front + $rear ) / 2);
            if ($mid * $mid > $num) {
                $rear = $mid - 1;
            } elseif ($mid * $mid < $num) {
                $front = $mid + 1;
            } else {
                return true;
            }
        }

        return false;
    }
}
```