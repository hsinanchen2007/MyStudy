方法一
```
function intToRoman($num,$string = "") {
    $arr = [1000,900,500,400,100,90,50,40,10,9,5,4,1];
    $code = ["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"];

    for ($a = 0;$a < count($arr);$a++){
        $string .= str_repeat($code[$a],intval($num / $arr[$a]));
        $num = $num % $arr[$a];
    }
    return $string;
}
```

方法二
```
function intToRoman2($num,$string = "") {
    if($num == 0){
        return $string;
    }
    $arr = [1000,900,500,400,100,90,50,40,10,9,5,4,1];
    $code = ["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"];

    for ($a = 0;$a < count($arr);$a++){
        if($num - $arr[$a] >= 0){
            $string .= $code[$a];
            return intToRoman($num - $arr[$a],$string);
        }
    }
}
```
