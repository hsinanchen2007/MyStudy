### 解题思路
此题目充分利用了两个数组都是已经排序好了的条件，通过创建两个指针位置，从头开始扫描两个数组，对比两个数组的值，
然后将小的push到新的数组。

最后需要注意退出循环的条件。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $A
     * @param Integer $m
     * @param Integer[] $B
     * @param Integer $n
     * @return NULL
     */
    function merge(&$A, $m, $B, $n) {
        $tmp = [];
        $i   = $j = 0;
        while ($i <= $n - 1 || $j <= $m - 1) {
            if ($i == $n) {
                array_push($tmp, $A[$j]);
                $j++;
                continue;
            }
            if ($j == $m) {
                array_push($tmp, $B[$i]);
                $i++;
                continue;
            }
            if ($B[$i] >= $A[$j]) {
                array_push($tmp, $A[$j]);
                $j++;
            } else {
                array_push($tmp, $B[$i]);
                $i++;
            }
        }

        return $A = $tmp;
    }
}
```