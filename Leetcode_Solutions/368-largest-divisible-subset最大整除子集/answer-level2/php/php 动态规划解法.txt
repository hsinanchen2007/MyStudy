```
function largestDivisibleSubset($nums) {
    $n = count($nums);
    if($n<=1) return $nums;
    $max = 0;
    $idx = -1;
    $dp = array_fill(0,$n,1);
    $path = array_fill(0,$n,-1);//整除下标的路径
    sort($nums);
    for($i=1;$i<$n;$i++){
        for($j=0;$j<$i;$j++){
            if($nums[$i]%$nums[$j]==0 && $dp[$i]<=$dp[$j]){
                $dp[$i] = $dp[$j]+1;
                $path[$i] = $j;
            }
        }
        if($dp[$i]>$max){
            $max = $dp[$i];
            $idx = $i;
        }
    }
    $ans = [];
    while($idx != -1){
        $ans[] = $nums[$idx];
        $idx = $path[$idx];
    }
    return $ans;
}
```
