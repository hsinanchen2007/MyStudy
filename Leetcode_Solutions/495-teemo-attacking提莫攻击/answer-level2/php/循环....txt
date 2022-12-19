```class Solution {

    /**
     * @param Integer[] $timeSeries
     * @param Integer $duration
     * @return Integer
     */
    function findPoisonedDuration($timeSeries, $duration) {
        $count = count($timeSeries);
        if($count < 1 || $duration == 0){
            return 0;
        }
        $res = $duration;
        $i = 1;

        while($i < $count){
            $res += $timeSeries[$i] - $timeSeries[$i-1] > $duration - 1 ? $duration : ($timeSeries[$i] - $timeSeries[$i-1]);
            $i++;
         }
        return $res;
    }
}
```
