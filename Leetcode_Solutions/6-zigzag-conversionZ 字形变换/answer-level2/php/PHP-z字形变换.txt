### 解题思路
1 使用二维数组存储对应字符的位置，最后输出整理结果字符串
2 采用标志位，标识存入方向的向上向下，注意边界条件

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @param Integer $numRows
     * @return String
     */
    function convert($s, $numRows) {
        $len = strlen($s);
        if ($len == 1 && $len == $numRows) return $s;
        $arr = [];
        $sign = 'down';
        $pre = -1;
        for ($i = 0; $i < $len; $i++) {
            if ($sign == 'down') {
                // 方向向下
                $arr[++$pre][] = $s[$i];
                // 到底部了，改方向为向上
                if ($pre == $numRows-1) $sign = 'up';
            } else {
                // 方向向上
                $arr[--$pre][] = $s[$i];
                // 到顶部了，改方向为向下
                if ($pre == 0) $sign = 'down';
            }
        }
        // 整理为字符串
        $resStr = '';
        foreach ($arr as $v) {
            foreach ($v as $vv) {
                $resStr .= $vv;
            }
        }
        return $resStr;
    }
}
```