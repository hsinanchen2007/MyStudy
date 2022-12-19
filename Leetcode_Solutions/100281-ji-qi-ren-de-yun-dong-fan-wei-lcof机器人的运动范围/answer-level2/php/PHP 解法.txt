### 解题思路
只需要向右和向下递推即可，使用一个数组存储已经访问过的位置。

当前位置的左和上两个位置，任意一个可以访问，当前位置就可以继续去判断。

### 代码

```php
class Solution
{
    /**
     * @param Integer $m
     * @param Integer $n
     * @param Integer $k
     * @return Integer
     */
    function movingCount($m, $n, $k)
    {
        $visted = array_fill(0, $m, array_fill(0, $n, 0));
        $visted[0][0] = 1;
        $count = 1;
        for ($i = 0; $i < $m; ++$i) {
            for ($j = 0; $j < $n; ++$j) {
                $sum = floor($i / 10) + $i % 10 + floor($j / 10) + $j % 10;
                if ($sum > $k) continue;
                // 左上两个，递推。向右下两个方向即可
                $a = $visted[$i - 1][$j] ?? 0;
                $b = $visted[$i][$j - 1] ?? 0;
                if ($a || $b) {
                    $visted[$i][$j] = 1;
                    $count++;
                }
            }
        }

        return $count;
    }
}
```