```
function twoSum($numbers, $target) {
    $left = 0;
    $right = count($numbers)-1;
    while($left<$right){
        if($numbers[$left]+$numbers[$right]==$target){
            return [$left+1,$right+1];
        }else if($numbers[$left]+$numbers[$right]>$target){
            $right--;
        }else{
            $left++;
        }
    }
    return [0,0];
}
```
