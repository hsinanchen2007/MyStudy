### 解题思路
1. 动态规划，模拟数据填入过程
2. $temp[$j] = $ans[$i-1][$j-1] + $ans[$i-1][$j]; //重要规则，当前元素由上层对应元素+前一元素之和
3. 非首行数据收尾均为：1

### 代码

```php
class Solution {

    /**
     * @param Integer $numRows
     * @return Integer[][]
     */
    function generate($numRows) {
        if($numRows < 1) return [];
        
        $ans = [[1]];
        for($i=1; $i<$numRows; $i++){
            $temp = [1];
            for($j=1; $j<count($ans[$i-1]); $j++){
                $temp[$j] = $ans[$i-1][$j-1] + $ans[$i-1][$j];
            }
            array_push($temp, 1);
            array_push($ans, $temp);
        }
        return $ans;
    }
}
```