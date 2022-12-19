```
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function countPrimes($n) {
        $a = [];
        for ($i=0;$i<$n;$i++) {
            $a[$i] = true;
        }
        
        $num = 0;
        for ($i=2;$i<$n;$i++) {
            if ($a[$i]) {
                $num++;
                for ($j=$i*$i;$j<$n;$j+=$i) {
                    
                    $a[$j] = false;
                }
            }
        }
        return $num;
    }
}
```
