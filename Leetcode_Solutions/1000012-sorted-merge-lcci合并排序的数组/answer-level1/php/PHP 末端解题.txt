### 解题思路
此处撰写解题思路

### 代码
本题的解题思路要取巧，也即配合A，B的指针位置，从A的末端开始填充，将最大数填充在m+n-1的位置。中间逻辑处理时，需要注意，m或者n一端取到0的位置，再将剩余的部分填充即可。
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
        $posA = $m - 1;
        $posB = $n - 1;
        $pos = $m + $n - 1;
        while ($pos >= 0 && ($posA >=0 || $posB >= 0)) {
            if ($posA < 0) {
                $A[$pos] = $B[$posB];
                $posB --;
                $pos --;
                continue;
            }
            if ($posB < 0) {
                $A[$pos] = $A[$posA];
                $posA --;
                $pos --;
                continue;
            }
            if ($B[$posB] >= $A[$posA]) {
                $A[$pos] = $B[$posB];
                $posB --;
            } else {
                $A[$pos] = $A[$posA];
                $posA --;
            }
            $pos --;
        }
        return $A;
    }
}
```