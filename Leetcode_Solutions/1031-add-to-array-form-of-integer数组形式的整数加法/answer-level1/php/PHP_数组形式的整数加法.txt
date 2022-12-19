```
function addToArrayForm($A, $K) {
    $len = count($A) - 1;
    $res = [];
    for ($i= $len; $i>=0; $i--) {
        if ($i >= 0) {
            $K += $A[$i];
            $mod = $K % 10;
            array_push($res, $mod);
            $K = intval($K / 10);
        } 
        
    }

    if ($K != 0) {
        array_push($res, $K);
    }
   $res = array_reverse($res);
   $res = implode('', $res);
    return $res;
 }

我这样在本地运行是可以的，但leetcode提交不了，也不知道怎么回事
```
