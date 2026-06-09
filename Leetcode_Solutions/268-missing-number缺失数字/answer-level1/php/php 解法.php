使用异或运算^进行抵消，剩下的就是缺失的数字
如：1^1^2^2^3 = 3
```
function missingNumber($nums) {
    $ans = count($nums);
    for($i=0;$i<count($nums);$i++){
        $ans ^= $nums[$i];
        $ans ^= $i;
    }
    return $ans;
}
```
