### 解题思路
由于是有序，则由大到小比较，$A的长度时知道的，设定 $p = $m + $n -1; 则比较大小放入对应位置即可

### 代码

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
        $p = $m + $n - 1;
        $m = $m - 1;
        $n = $n - 1;
        while ($m >= 0 || $n >= 0) {
            if ($m == -1) {
                $A[$p] = $B[$n];
                $n--;
            } else if ($n == -1) {
                $A[$p] = $A[$m];
                $m--;
            } else if ($A[$m] > $B[$n]) {
                $A[$p] = $A[$m];
                $m--;
            } else if ($A[$m] <= $B[$n]) {
                $A[$p] = $B[$n];
                $n--;
            }
            $p--;
        }
        
        return $A;
    }
}
```