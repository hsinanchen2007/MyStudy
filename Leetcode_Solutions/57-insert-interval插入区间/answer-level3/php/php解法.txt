只需要一次for循环遍历
```
function insert($intervals, $newInterval) {
    if(count($intervals)<1) return [$newInterval];
    if(count($newInterval)<1) return $intervals;
    // sort($intervals); //已经注释，题目说明已经排序
    $n = count($intervals);
    $is_merge = false;
    for($i=0;$i<$n;$i++){
        $start = $intervals[$i][0];
        $end = $intervals[$i][1];
        // 先处理插入情况
        if($i == 0 && $start > $newInterval[1]){
            array_unshift($intervals,$newInterval);
            return $intervals;
        }else if($i == $n-1 && $end < $newInterval[0]){
            array_push($intervals,$newInterval);
            return $intervals;
        }else if($i >= 0 && $i < $n-1 && $end < $newInterval[0] && $intervals[$i+1][0] > $newInterval[1]){
            array_splice($intervals,$i+1,0,array($newInterval));
            return $intervals;
        }
        // 合并边界情况
        if(!$is_merge){
            if(($start <= $newInterval[0] && $end >= $newInterval[0]) 
                || ($start <= $newInterval[1] && $end >= $newInterval[1]) 
                || ($start >= $newInterval[0] && $start <= $newInterval[1]) 
                || ($end >= $newInterval[0] && $end <= $newInterval[1])){
                $intervals[$i][0] = min($start,$newInterval[0]);
                $intervals[$i][1] = max($end,$newInterval[1]);
                $is_merge = true;
            }
        }else{
            if($start <= $intervals[$i-1][1]){
                $intervals[$i][0] = $intervals[$i-1][0];
                $intervals[$i][1] = max($intervals[$i-1][1],$end);
                unset($intervals[$i-1]);
            }else{
                return $intervals;
            }
        }
    }
    return $intervals;
}
```
