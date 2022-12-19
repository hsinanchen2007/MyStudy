### 解题思路
动态规划解法，重点是找到状态转移方程 `$arr[$i][$j] = $arr[$i - 1][$j] + $arr[$i][$j - 1];`

注意边界条件的处理，最右侧和最下侧值都为 1

### 代码

```php
class Solution {

    /**
     * @param Integer $m
     * @param Integer $n
     * @return Integer
     */
    function uniquePaths($m, $n) {
        $arr = [];
        for ($i = 1; $i <= $m; $i++) {
            for ($j = 1; $j <= $n; $j++) {
                if ($i == 1 || $j == 1) {
                    $arr[$i][$j] = 1;
                } else {
                    $arr[$i][$j] = $arr[$i - 1][$j] + $arr[$i][$j - 1];
                }
            }
        }
        return $arr[$m][$n];
    }
}
```

知识点

```php
// array fill 填充二维数组
$map = array_fill(0, $m, array_fill(0, $n, 1));
```