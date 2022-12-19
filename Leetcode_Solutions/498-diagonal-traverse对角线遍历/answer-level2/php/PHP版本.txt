### 解题思路
1.确定坐标x,y关系。
2.确定x,y初始值。
3.确定x,y结束值。
4.确定x,y循环值的变化规律。
### 代码

```php
class Solution {

    /**
     * @param Integer[][] $matrix
     * @return Integer[]
     */
    function findDiagonalOrder($matrix) {
                //获取二维数组中一维数组的个数(矩阵的行)
        $m = count($matrix);
        if ($m == 0) {
            return $matrix;
        }
        //获取一维数组上元素的个数(矩阵的列)
        $n = count($matrix[0]);
        if ($n == 0) {
            return $matrix;
        }
        
        //$flag标志x,y顺序取反向,默认从x开始
        $flag = true;
        
        //输出的结果
        $reulst = array();
        //$i = $x + $y;
        for ($i = 0; $i < ($m + $n); $i++) {
            $pm = $flag ? $m : $n;
            $pn = $flag ? $n : $m;
            
            //确定x,y的初始值
            $x = ($i < $pm) ? $i : $pm - 1;
            $y = $i - $x;
            
            //结束一趟循环的条件
            while($x >= 0 && $y < $pn){
                $result[] = $flag ? $matrix[$x][$y] : $matrix[$y][$x];
                $x--;
                $y++;
            }
            $flag = !$flag;
        }
        
        return $result;
    }
}
```