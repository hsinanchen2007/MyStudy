### 解法一 两次循环

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function dominantIndex($nums) {
        $length = count($nums);
        if ($length == 0) {
            return -1;
        } elseif ($length == 1) {
            return 0;
        }

        $maxIndex = -1;
        $max = PHP_INT_MIN;
        for ($i = 0; $i < $length; ++$i) {
            if ($nums[$i] > $max) {
                $max = $nums[$i];
                $maxIndex = $i;
            }
        }

        for ($i = 0; $i < $length; ++$i) {
            if ($i != $maxIndex && $nums[$i] * 2 > $max) {
                return -1;
            }
        }

        return $maxIndex;
    }
}
```

### 解法二 利用 PHP 内置函数处理

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function dominantIndex($nums) {
       // 对关联数组按照键值进行降序排序，可以保留数值键
        arsort($nums);
        if (current($nums) >= next($nums) * 2) {
            // 将内部指针指向数组中的第一个元素，并输出
            reset($nums);
            // 返回数组内部指针当前指向元素的键名
            return key($nums);
        }

        return -1;
    }
}
```