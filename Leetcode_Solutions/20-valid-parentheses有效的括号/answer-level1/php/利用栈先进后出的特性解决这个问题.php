```
function isValid($s)
{
    $strlength = strlen($s);
    // 奇数长度的字符串肯定不对
    if ($strlength % 2 == 1) {
        return false;
    }

    $temp = [];
    $left = ['(' => ')', '[' => ']', '{' => '}'];
    for ($i = 0; $i < $strlength; $i++) { 
        if (isset($left[$s[$i]])) {
            array_push($temp, $s[$i]); 
        } else {
            $leftString = array_pop($temp);
            if ($left[$leftString] != $s[$i]) {
                return false;
            }
        }
    }

    // 偶数长度的字符串也不一定对, 因为可能遇到‘{(’这样的字符串, 所以需要判断数组全部出栈后的长度，如果长度大于0说明字符串内的括号不对称, 则返回false
    return count($temp) == 0 ? true : false; 
}
```
