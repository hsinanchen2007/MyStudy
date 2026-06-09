```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function findShortestSubArray($nums) {
        $hash = [];
        foreach($nums as $k=>$v){
            $hash[$v]['count'] =  isset($hash[$v]) ? $hash[$v]['count']+=1 : 1;
            $hash[$v]['key'][] = $k;
        }
        $max = 0;$karr = [];
        foreach ($hash as $k => $v) {
            if ($v['count'] > $max) 
            {
                $max = $v['count'];
                unset($karr);
                $karr[] = $k;
            } else  if ($v['count'] == $max) 
            {
                $karr[] = $k;
            }
 
        }
        foreach ($karr as $k=>$v) { 
            $juli[]   = max($hash[$v]['key'])-min($hash[$v]['key'])+1;
        }
            return min($juli);
    }
}
```
