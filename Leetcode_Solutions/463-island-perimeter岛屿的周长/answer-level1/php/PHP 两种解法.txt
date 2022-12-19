### 解法一 遍历每一个节点，如果为陆地，边长贡献值加 4。再寻找其四个方向，每个方向如果是陆地，贡献值减 1

```php
class Solution
{
    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function islandPerimeter($grid)
    {
        $row = count($grid);
        if ($row == 0) return 0;
        $col = count(reset($grid));
        $sum = 0;
        $directions = [[-1, 0], [0, -1], [1, 0], [0, 1]];
        // 每个节点的贡献值
        for ($i = 0; $i < $row; ++$i) {
            for ($j = 0; $j < $col; ++$j) {
                if ($grid[$i][$j] == 1) {
                    $line = 4;
                    for ($n = 0; $n < 4; ++$n) {
                        $newX = $i + $directions[$n][0];
                        $newY = $j + $directions[$n][1];
                        if (isset($grid[$newX][$newY]) && $grid[$newX][$newY] == 1) {
                            $line--;
                        }
                    }
                    $sum += $line;
                }
            }
        }

        return $sum;
    }
}
```

### 解法二 与解法一基本相同，只寻找其左侧节点和上面的节点，每个节点的贡献值减少 2.计算量减半

```php
class Solution
{
    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function islandPerimeter($grid)
    {
        $row = count($grid);
        if ($row == 0) return 0;
        $col = count(reset($grid));
        $sum = 0;
        $directions = [[-1, 0], [0, -1], [1, 0], [0, 1]];
        // 每个节点的贡献值 左侧有，减 2，上面有，也减 2
        for ($i = 0; $i < $row; ++$i) {
            for ($j = 0; $j < $col; ++$j) {
                if ($grid[$i][$j] == 1) {
                    $line = 4;
                    if (isset($grid[$i][$j - 1]) && $grid[$i][$j - 1]) $line -= 2;
                    if (isset($grid[$i - 1][$j]) && $grid[$i - 1][$j]) $line -= 2;
                    $sum += $line;
                }
            }
        }

        return $sum;
    }
}
```