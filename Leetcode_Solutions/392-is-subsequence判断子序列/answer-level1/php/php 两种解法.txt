解法一：双指针-初版
```
function isSubsequence($s, $t) {
    if(strlen($s)==0) return true;
    $ps = 0;
    $pt = 0;
    while($ps < strlen($s) && $pt < strlen($t)){
        while($pt < strlen($t) && $s[$ps] != $t[$pt]) $pt++;
        if($ps == strlen($s)-1 && $s[$ps] == $t[$pt]) return true;
        $ps++;
        $pt++;
    }
    return false;
}
```
解法一：双指针-优化代码
```
function isSubsequence($s, $t) {
    if(strlen($s)==0) return true;
    $ps = 0;
    $pt = 0;
    while($ps < strlen($s) && $pt < strlen($t)){
        if($s[$ps] == $t[$pt]) $ps++;
        $pt++;
    }
    return !isset($s[$ps]);
}
```
解法二：优化遍历。由于字符串t比较长，遍历它比较花时间，所以选择遍历s字符串。该方法8ms，100%。
```
function isSubsequence($s, $t) {
        $index = -1;
        for($i=0;$i<strlen($s);$i++){
            $index = strpos($t,$s[$i],$index+1);
            if($index === false) return false;
        }
        return true;
    }
```