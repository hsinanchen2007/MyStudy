### 解题思路一
思路一：使用两层循环
0、外层循环决定有多少层。
1、内层循环决定没层的数据。

![triangle.JPG](https://pic.leetcode-cn.com/94027bf0fc6f0d6c9e8629abde25a62033498986841f4cd585ec79a64766d668-triangle.JPG)


算法：
0、从0开始遍历每一层。
1、遍历当前层的时候，把当前层的数据存在临时变量$tmp中，初始化为只有一个元素1的数组。
2、遍历当前层上层的元素，每次把上层相邻的元素加和，追加到$tmp中。
3、当前层上层的元素遍历完成后，当前层的数据就生成完成，放到终止结果中。

参考：https://leetcode-cn.com/problems/pascals-triangle/solution/dong-tai-gui-hua-by-norazh/

### 代码

```php
class Solution {

    /**
     * @param Integer $numRows
     * @return Integer[][]
     */
    function generate($numRows) {
        $triangle = [];
        for ($i = 0; $i < $numRows; $i++) {
            $tmp = [1];
            for ($j = 0; $j < $i; $j++) {
                // 当$j = $i - 1的时候，已经说明已经是最后一个元素了，单独处理
                // 理论上$j == $i - 1的概率比较小，放到else效率应该更高，实际测试没有区别
                if ($j == $i - 1) {
                    $tmp[] = $triangle[$i - 1][$j];
                } else {
                    $tmp[] = $triangle[$i - 1][$j] + $triangle[$i - 1][$j + 1];
                }
            }

            $triangle[] = $tmp;
        }

        return $triangle;
    }
}

```

### 解题思路二
思路二、动态规划

算法：
0、状态:
$dp[0] = [1];
$dp[1] = [1,1];
1、状态转移方程：
$dp[$i][] = $dp[$i-1][$j-1]+$dp[$i-1][$j];

```

### 代码
/**
     * @param Integer $numRows
     * @return Integer[][]
     */
    function generate($numRows)
    {
        if ($numRows == 0) {
            return [];
        }

        if ($numRows == 1) {
            return [[1]];
        }

        $dp[0] = [1];
        $dp[1] = [1,1];
        for($i = 2; $i < $numRows; $i++) {
            $dp[$i][] = 1;
            for($j = 1; $j < $i; $j++) {
                $dp[$i][] = $dp[$i-1][$j-1]+$dp[$i-1][$j];
            }
            $dp[$i][] = 1;
        }
        
        return $dp;
    }
```
