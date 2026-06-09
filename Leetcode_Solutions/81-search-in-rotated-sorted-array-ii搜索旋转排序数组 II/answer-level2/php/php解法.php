相对于31题多了一步处理重复元素的操作
```
function search($nums, $target) {
    $left = 0;
    $right = count($nums)-1;
    while($left<=$right){
        $mid = $left + floor(($right-$left)/2);
        if($target == $nums[$mid]) return true;
        if($nums[$mid]==$nums[$left] && $nums[$mid]==$nums[$right]){
            $left++;
            $right--;
        }else if($nums[$mid]>=$nums[$left]){//mid前半部分有序
            if($target>=$nums[$left] && $target<$nums[$mid]){
                $right = $mid-1;
            }else{
                $left = $mid+1;
            }
        }else{//mid后半部分有序
            if($target<=$nums[$right] && $target>$nums[$mid]){
                $left = $mid+1;
            }else{
                $right = $mid-1;
            }
        }
    }
}
```
