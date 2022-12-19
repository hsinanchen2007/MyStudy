### 解题思路
先检查是否可以转换，可以转换的时候遍历填充，通过除以列数，商是对于行，余数对于列。

### 性能
执行用时 :36 ms, 在所有 PHP 提交中击败了52.38%的用户
内存消耗 :19.3 MB, 在所有 PHP 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $nums
     * @param Integer $r
     * @param Integer $c
     * @return Integer[][]
     */
    function matrixReshape($nums, $r, $c) {
        $x = count($nums);
        $y = count($nums[0]);
        if ($x * $y != $r * $c) return $nums;

        $res = [];
        for ($i = 0; $i < $x * $y; $i++) {
            $res[intval($i / $c)][$i % $c] = $nums[intval($i / $y)][$i % $y];
        }

        return $res;
    }
}
```