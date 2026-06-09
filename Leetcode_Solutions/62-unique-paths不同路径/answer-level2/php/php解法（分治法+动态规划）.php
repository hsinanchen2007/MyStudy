### 解题思路
1.利用分治法的思想求解
用数组可以做一个缓存，优化算法的性能
2.利用动态规划的思想求解

### 代码
1.分治法的思想
```
class Solution {
    public $arr = array();   //缓存计算过的数据
    /**
     * @param Integer $m
     * @param Integer $n
     * @return Integer
     */
    function uniquePaths($m, $n) {
        $this->helper($m, $n, 0, 0);
        return $this->arr[0][0];
    }
    function helper($m, $n, $i, $j) {
        if ($i+1 >= $m || $j+1 >= $n) {   //边界
            return $this->arr[$i][$j] = 1;
        }
        if (isset($this->arr[$i][$j])) {
            return $this->arr[$i][$j];
        }
        $arr[$i+1][$j] = $this->helper($m, $n, $i+1, $j);
        $arr[$i][$j+1] = $this->helper($m, $n, $i, $j+1);
        $this->arr[$i][$j] = $arr[$i+1][$j] + $arr[$i][$j+1];
        return $this->arr[$i][$j];
    }
}
```
2.动态规划思想
```php
class Solution {
    /**
     * @param Integer $m
     * @param Integer $n
     * @return Integer
     */
    function uniquePaths($m, $n) {
        $arr = array();
        //最下一边
        for ($i = 0; $i < $m; $i++) {
            $arr[$i][$n-1] = 1;
        }
        //最右一边
        for ($j = 0; $j < $n; $j++) {
            $arr[$m-1][$j] = 1;
        }
        //逐层向起点递推
        for ($jj = $n-2; $jj >=0; $jj--) {
            for ($ii = $m-2; $ii >=0; $ii--) {
                $arr[$ii][$jj] = $arr[$ii+1][$jj] + $arr[$ii][$jj+1];
            }
        }
        return $arr[0][0];
        
    }
}
```