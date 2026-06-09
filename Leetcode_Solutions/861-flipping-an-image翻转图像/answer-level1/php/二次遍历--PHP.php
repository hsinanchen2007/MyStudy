### 解题思路
遍历用1减去最后一行的数实现取反，同时把数放到新数组末尾，实现逆序。

注意：PHP中数组顺序是放入顺序决定的，不是下标顺序。
故而以下语句跟期望相反
```
$B[$i][$col - $j - 1] = 1 - $A[$i][$j];
```


### 性能
执行用时 :16 ms, 在所有 PHP 提交中击败了58.06%的用户
内存消耗 :14.9 MB, 在所有 PHP 提交中击败了32.14%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $A
     * @return Integer[][]
     */
    function flipAndInvertImage($A) {
        $row = count($A);
        $col = count($A[0]);
        for ($i = 0; $i < $row; $i++) {
            $cur = [];
            for ($j = 0; $j < $col; $j++) {
                // $B[$i][$col - $j - 1] = 1 - $A[$i][$j];
                array_unshift($cur, 1 - $A[$i][$j]);
            }
            $B[$i] = $cur;
        }
        
        return $B;
    }
}
```