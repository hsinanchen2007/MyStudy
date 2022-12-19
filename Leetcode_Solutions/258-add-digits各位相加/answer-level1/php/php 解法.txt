非常规解法,找规律：只要数字大于9，答案就是被9除的余数。
```
function addDigits($num) {
    if($num<=9) return $num;
    $num = fmod($num,9);
    return $num==0?9:$num;
}
```
