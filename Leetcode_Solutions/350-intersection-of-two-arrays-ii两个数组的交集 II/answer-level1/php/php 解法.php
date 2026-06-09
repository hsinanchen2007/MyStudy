```
function intersect($nums1, $nums2) {
    sort($nums1);
    sort($nums2);
    $ans = [];
    for($i=0,$j=0; $i<count($nums1)&&$j<count($nums2); ){
        if($nums1[$i] < $nums2[$j]){
            $i++;
        }else if($nums1[$i] > $nums2[$j]){
            $j++;
        }else{
            $ans[] = $nums1[$i];
            $i++;
            $j++;
        }
    }
    return $ans;
}
```
