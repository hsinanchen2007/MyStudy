审题：你不需要考虑数组中超出新长度后面的元素
```
function removeElement(&$nums, $val) {
    $i = 0;
    foreach($nums as $k=>$v){
        if($v!=$val){
            $nums[$i] = $v;
            $i++;
        }
    }
    return $i;
}
```
在数组长度未知的情况下foreach确实比for效率高一点点。
