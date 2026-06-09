先对数组排序，通过mid分割为大数部分和小数部分，再逆序穿插排序。
```
function wiggleSort(&$nums) {
    sort($nums);
    $mid = floor((count($nums)-1)/2);
    $arr = [];
    $n = count($nums)-1;
    for($i=$mid;$i>=0;$i--){
        $arr[] = $nums[$i];
        if($n>$mid) $arr[] = $nums[$n];
        $n--;
    }
    $nums = $arr;
}
```
