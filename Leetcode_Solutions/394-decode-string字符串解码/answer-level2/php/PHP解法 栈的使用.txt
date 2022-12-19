```php
function decodeString($s)
{
    // 初始化结果为空
    $res = '';
    $len = strlen($s);
    // 初始化倍数
    $multi = 0;
    // 初始化倍数数组
    $stackMulti = array();
    // 初始化结果暂存处
    $stackRes = array();

    for ($i = 0; $i < $len; $i++) {

        if ($s[$i] == '[') {
            array_push($stackMulti,$multi);
            // 因为接下来可能有新的字符了，所以先把之前的结果压栈存储
            array_push($stackRes,$res);

            // $res 与 $multi 初始化是为了后面的使用
            $res = '';
            $multi = 0;

        }else if ($s[$i] == ']') {
            $curMulti = array_pop($stackMulti);
            $tmp = '';

            for ($j = 0; $j < $curMulti; $j++) {
                $tmp .= $res;
            }

            $res = array_pop($stackRes).$tmp;
        }else if ($s[$i] >= '0' && $s[$i] <= '9') {
            $multi = $multi * 10 + intval($s[$i]);
        }else {
            $res .= $s[$i];
        }

    }

    return $res;
}
```
