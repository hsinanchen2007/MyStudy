### 解题思路
1. 找到生成三角的遍历方法
2. 判断三角型的两个腰边和顶点为1
3. 找到求解第二层的规律
4. 虽然我的内层索引是反的但是杨辉三角是等腰三角形,中心对称嘛.一样的

### 代码

```php
class Solution {

    /**
     * @param Integer $numRows
     * @return Integer[][]
     */
    function generate($numRows) {
        $arr = [];
        for ($i=0;$i<$numRows;$i++) {
            for ($j=$i;$j>=0;$j--) {
                if ($j==0 || $j==$i) {
                    $arr[$i][$j] = 1;
                } else {
                    $arr[$i][$j] = $arr[$i-1][$j-1] + $arr[$i-1][$j];
                }
            }
        }
        return $arr;
    }
}
```