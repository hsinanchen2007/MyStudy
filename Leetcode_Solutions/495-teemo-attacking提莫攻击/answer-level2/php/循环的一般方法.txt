class Solution {

    /**
     * @param Integer[] $timeSeries
     * @param Integer $duration
     * @return Integer
     */
    function findPoisonedDuration($timeSeries, $duration) {
        if(empty($timeSeries))
        {
            return 0;
        }
        $sum[] = $duration;
        for($i=0;$i<count($timeSeries)-1;$i++)
        {
            if($timeSeries[$i]+$duration <= $timeSeries[$i+1])
            {
                $sum[] = $duration;
            }
            else
            {
                $sum[] = $duration-($duration-($timeSeries[$i+1]-$timeSeries[$i]));
            }
        }
        return array_sum($sum);
    }
}