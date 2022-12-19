### 解题思路
动态规划

### 代码

```php
class Solution {

    /**
     * @param Integer[] $A
     * @param Integer[] $B
     * @return Integer
     */
    function findLength($A, $B) {
        $m = count($A);
        $n = count($B);
        $dp = array_fill(0,$m+1,array_fill(0,$n+1,0));

        $max = 0;
        for($i=1;$i<=$m;$i++){
            for($j=1;$j<=$n;$j++){
                if($A[$i-1] == $B[$j-1]){
                    $dp[$i][$j] = $dp[$i-1][$j-1] + 1;
                    if($dp[$i][$j]>$max){
                        $max = $dp[$i][$j];
                    }
                }
            }
        }
        return $max;
    }
}
```