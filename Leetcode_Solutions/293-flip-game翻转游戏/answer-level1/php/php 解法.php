```
function generatePossibleNextMoves($s) {
    if(strlen($s) <= 0) return [];
    $ans = [];
    for($i=1;$i<strlen($s);$i++){
        if($s[$i-1]=='+' && $s[$i]=='+'){
            $tmp = $s;
            $tmp[$i-1] = '-';
            $tmp[$i] = '-';
            $ans[] = $tmp;
        }
    }
    return $ans;
}
```
