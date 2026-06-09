看了几个 PHP 相关题解，都过于依赖语言特性了，
现在是在做算法题，尽量减少对语言特性的依赖，采用更加普适的方法去解决问题

双指针解法，看起来挺复杂的，时间复杂度也不太优秀

```php
function removeElement(&$nums, $val) {
    $len = count($nums);
    if ($len == 0) {
        return 0;
    }

    $left = 0;
    $right = $len - 1;
    while ($left <= $right) {
        if ($nums[$right] == $val) {
            $right--;
            $len--;
        } elseif ($nums[$left] == $val) {
            $nums[$left] = $nums[$right];
            $nums[$right] = $val;
            $right--;
            $left++;
            $len--;
        } else {
            $left++;
        }
    }

    return $len;
}
```
