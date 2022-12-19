### 解题思路
纯模拟，按照题目描述给的形状写入一个二维数组中，最后再依次输出即可。
此方法理解比较简单，就是内存消耗有点多，时间还行。

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @param Integer $numRows
     * @return String
     */
    function convert($s, $numRows) {
        $ls = [];
        $x = 0; $y = 0;
        if($numRows == 1) return $s;
        for($i = 0; $i < strlen($s); ++$i) {
            $ls[$y][$x] = $s[$i];
            if($x % ($numRows - 1) == 0) {
                if($y == ($numRows - 1)) {
                    --$y;
                    ++$x;
                } else {
                    ++$y;
                }
            } else {
                --$y;
                ++$x;
            }
        }
        $str = "";
        for($i = 0; $i < $numRows; ++$i) {
            foreach($ls[$i] as $k => $v) {
                $str .= $v;
            }
        }
        return $str;
    }
}
```