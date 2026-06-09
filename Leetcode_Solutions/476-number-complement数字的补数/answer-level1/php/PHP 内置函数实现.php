```
function findComplement($num)
{
    // 利用PHP自带的函数解决
    $newNum = decbin($num);
    $str    = '';
    for ($i = 0; $i < strlen($newNum); $i++) {
        if ($newNum[$i] == 0) {
            $str .= 1;
        } else {
            $str .= 0;
        }
    }
    return bindec($str);
}
```