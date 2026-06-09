```
function increasingTriplet($nums) {
    $one = PHP_INT_MAX;
    $two = PHP_INT_MAX;
    foreach($nums as $num){
        if($num <= $one){
            $one = $num;
        }else if($num <= $two){
            $two = $num;
        }else{
            return true;
        }
    }
    return false;
}
```
