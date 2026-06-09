```
function shortestDistance($words, $word1, $word2) {
    $p1 = $p2 = -1;
    $ans = PHP_INT_MAX;
    for($i=0;$i<count($words);$i++){
        if($words[$i] == $word1){
            $p1 = $i;
            if($p2 != -1) $ans = min($ans,$p1-$p2);
        }else if($words[$i] == $word2){
            $p2 = $i;
            if($p1 != -1) $ans = min($ans,$p2-$p1);
        }
    }
    return $ans;
}
```
