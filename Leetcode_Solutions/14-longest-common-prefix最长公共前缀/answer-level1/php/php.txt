```
function longestCommonPrefix($strs) {
    $s = "";
    for($a = 0;$a < strlen($strs[0]);$a++){
        $c = true;
        foreach ($strs as $key => $value){
            if($value[$a] != $strs[0][$a]){
                $c = false;
                break;
            }
        }
        if($c == false){
            break;
        }
        $s .= $strs[0][$a];
    }
    return $s;
}
```
