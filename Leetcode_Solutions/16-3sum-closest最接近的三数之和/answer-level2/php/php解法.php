```
function threeSumClosest($nums, $target) {
    if(count($nums)<=3) return array_sum($nums);
    sort($nums);
    $res = null;
    $dis = null;
    for($i=0;$i<count($nums)-2;$i++){
        $left = $i+1;
        $right = count($nums)-1;
        
        while($left<$right){
            $sum = $nums[$i] + $nums[$left] + $nums[$right];
            if($dis === null || $res === null){
                $res = $sum;
                $dis = abs($sum - $target);
            }
            if($dis>abs($sum - $target)){
                $res = $sum;
                $dis = abs($sum - $target);
            }
            if($sum - $target>0){
                $right --;
            }else if ($sum - $target<0){
                $left ++;
            }else{
                return $res;
            }
        }
    }
    return $res;
}
```
