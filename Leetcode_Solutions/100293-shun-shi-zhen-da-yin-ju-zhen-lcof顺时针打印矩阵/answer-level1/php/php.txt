### 解题思路
此处撰写解题思路
本题的思路比较清晰，就是按照顺时针方向遍历数组，不过需要细心的地方就是想清楚边界（偷懒的方式是调试），然后遍历终止条件是遍历个数等于数组的个数。我这里加了一个循环次数，用来设定边界，代码如下
### 代码

```php
class Solution {

    /**
     * @param Integer[][] $matrix
     * @return Integer[]
     */
    function spiralOrder($matrix) {
        //第n层循环 1...n
        //右移动 col++->countCol - n
        //下移动 row ++->countRow - n
        //左移动 col -- -> n - 1
        //上移动  row -- -> n
        $n = 1;
        $num = count($matrix) * count($matrix[0]);
        $i = 0;
        $countCol = count($matrix[0]);
        $countRow = count($matrix);
        $arr = [];
        while ($i < $num) {
            $row = $col = $n - 1;
            for ($p = $col; $p <= $countCol - $n; $p ++) {
                $arr[] = $matrix[$row][$p];
                $i ++;
                if ($i >= $num) {
                    break 2;
                }
            }
            for ($p = $row + 1; $p <= $countRow - $n; $p ++) {
                $arr[] = $matrix[$p][$countCol - $n];
                $i ++;
                if ($i >= $num) {
                    break 2;
                }
            }
            for ($p = $countCol - $n - 1; $p >= $n - 1; $p --) {
                $arr[] = $matrix[$countRow - $n][$p];
                $i ++;
                if ($i >= $num) {
                    break 2;
                }
            }
            for ($p = $countRow - $n - 1; $p > $row; $p --) {
                $arr[] = $matrix[$p][$col];
                $i ++;
                if ($i >= $num) {
                    break 2;
                }
            }
            $n ++;
        }
        return $arr;
    }
}
```