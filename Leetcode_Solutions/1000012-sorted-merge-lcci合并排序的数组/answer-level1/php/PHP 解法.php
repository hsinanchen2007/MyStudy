参考官方题解的倒序双指针解法，实现原地排序

```php
class Solution
{

    /**
     * @param Integer[] $A
     * @param Integer $m
     * @param Integer[] $B
     * @param Integer $n
     * @return NULL
     */
    function merge(&$A, $m, $B, $n)
    {
        // 指针设置为从后向前遍历，每次取两者之中的较大者放进 A 的最后面。
        $posA = $m - 1;
        $posB = $n - 1;
        while ($posA >= 0 || $posB >= 0) {
            if ($posA < 0) {
                $A[$posB] = $B[$posB];
                $posB--;
            } elseif ($posB < 0) {
                $posA--;
            } else {
                if ($A[$posA] >= $B[$posB]) {
                    $A[$posA + $posB + 1] = $A[$posA];
                    $posA--;
                } else {
                    $A[$posA + $posB + 1] = $B[$posB];
                    $posB--;
                }
            }
        }
        return $A;
    }
}
```