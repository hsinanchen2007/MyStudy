仿java

递归解法：
```
function isMatch($s, $p) {
    if(empty($p)) return empty($s);
    $first_match = !empty($s) && ($p[0]==$s[0] || $p[0]=='.');
    
    if(strlen($p)>=2 && $p[1]=='*'){
        return $this->isMatch($s, substr($p,2)) || ($first_match && $this->isMatch(substr($s,1), $p));
    }else{
        return $first_match && $this->isMatch(substr($s,1), substr($p,1));
    }
}
```
动态规划解法：
```
function isMatch($s, $p) {
    $m = strlen($s);
    $n = strlen($p);
    $f = array_fill(0,$m+1,array_fill(0,$n+1,false));
    $f[0][0] = true;
    for($k = 2; $k <= $n; $k++){
        $f[0][$k] = $f[0][$k - 2] && $p[$k - 1] == '*';
    }
    for($i = 1; $i <= $m; $i++){
        for($j = 1; $j <= $n; $j++){
            if($s[$i - 1] == $p[$j - 1] || $p[$j - 1] == '.'){
                $f[$i][$j] = $f[$i - 1][$j - 1];
            }
            if($p[$j - 1] == '*'){
                $f[$i][$j] = $f[$i][$j - 2] || 
                $f[$i - 1][$j] && ($s[$i - 1] == $p[$j - 2] || $p[$j - 2] == '.');
            }
        }
    }
    return $f[$m][$n];
}
```
