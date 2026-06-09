### 解题思路
官方解法

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $matrix
     * @return NULL
     */
    function rotate(&$matrix) {
        // $tem = count($matrix)-1;
        // for ($i = 0; $i < count($matrix); $i++) {
        //     for ($j= 0; $j< count($matrix); $j++) {
        //         array_push($matrix[$i],$matrix[$tem-$j][$i]);
        //     }
        // }
        // for ($k = 0; $k < $tem+1; $k++) {
        //     array_splice($matrix[$k], 0, $tem+1);
        // }
        // return $matrix;

        $n = count($matrix);
        for($i=0;$i<$n;$i++){
            for($j=$i;$j<$n;$j++){
                $tmp = $matrix[$i][$j];
                $matrix[$i][$j] = $matrix[$j][$i];
                $matrix[$j][$i] = $tmp;
            }
        }

        // print_r($matrix);

        for($i=0;$i<$n;$i++){
            for($j=0;$j<floor($n/2);$j++){
                $tmp = $matrix[$i][$j];
                $matrix[$i][$j] = $matrix[$i][$n-$j-1];
                $matrix[$i][$n-$j-1] = $tmp;
            }
        }

    }

    
}
```