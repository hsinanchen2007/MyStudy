### 解题思路
从中间开始找。

### 性能
执行用时 :8 ms, 在所有 PHP 提交中击败了75.00%的用户
内存消耗 :15.2 MB, 在所有 PHP 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer $area
     * @return Integer[]
     */
    function constructRectangle($area) {
        $width = intval(sqrt($area));
        while ($area % $width != 0) {
            $width--;
        }

        return [$area / $width, $width];
    }
}
```