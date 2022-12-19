```
class Solution {

    /**
     * @param Integer[] $time
     * @return Integer
     */
    function numPairsDivisibleBy60($time) {
        $count = count($time);
        $times=0;
        $hash = [];
        for ($i=0;$i<$count;$i++) {
            if (isset($hash[$time[$i] % 60])) {
                $hash[$time[$i] % 60] += 1;    
            } else {
                $hash[$time[$i] % 60] = 1;
            }
        }
        $times = ($hash[0] * ($hash[0] - 1) + $hash[30] * ($hash[30]-1))>>1;
        for ($i=0;$i<30;$i++) {
            $times += $hash[$i] * $hash[60 - $i];
        }
        return $times;
    }
}
```
