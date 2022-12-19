```
function canPermutePalindrome($s) {
    $map = [];
    for($i = 0; $i < strlen($s); $i++){
        if(isset($map[$s[$i]])){
            unset($map[$s[$i]]);
        }else{
            $map[$s[$i]] = 1;
        }
    }
    return count($map) <= 1;
}
```
