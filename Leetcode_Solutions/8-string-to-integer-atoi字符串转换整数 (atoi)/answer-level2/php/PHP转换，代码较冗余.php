实际上这道题真的试错了好多次，给人的感觉就像是看着测试用例，挨着挨着改。这里就不多赘述，下面给出具体的解法，代码中包含注释。写得不咋好，欢迎指正。
```
function myAtoi($str)
{
    $str    = trim($str);   //去掉所有空字符
    $length = strlen($str);
    $result = '';
    for ($i = 0; $i < $length; $i++) {
        if ($i == 0 && $str[$i] != '-' && $str[$i] != '+' && !is_numeric($str[$i])) {
            //Step 1: 当第一个字符不为正负号或非数字，则直接返回0
            return 0;
        }
        if ($i == 0 && ($str[$i] == '-' || $str[$i] == '+' || is_numeric($str[$i]))) {
            //Step 2: 如果第一个字符是正负号或数字，则直接链接字符串
            $result .= $str[$i];
        }
        if ($i > 0) {
            if ($i == 1) {
                //在经过Step1, Step 2后，第一个字符要么是数字，要么就是正负号，则直接进行连接，这就可能后面连续都是0，这个放在后续处理
                if (is_numeric($str[$i]) && (is_numeric($str[$i - 1]) || $str[$i - 1] == '-' || $str[$i - 1] == '+')) {
                    $result .= $str[$i];
                } else {
                    break;
                }
            } else {
                //在下标1过了后，就只需要判断当前下标和前一个下标对应值是否为数字即可，直接进行连接。
                if (is_numeric($str[$i]) && is_numeric($str[$i - 1])) {
                    $result .= $str[$i];
                } else {
                    break;
                }
            }
        }
    }
    if (isset($result[0]) && $result[0] == '+') {
        $result = substr($result, 1);
    }
    if (isset($result[0]) && $result[0] == '-') {
        $result = substr($result, 1);
        $result = ltrim($result, '0');
        $result = '-'.$result;
    }
    $result = ltrim($result, '0');
//    $result = intval($result);   //也可以直接使用类型转换（即可概括以上两个if语句块），即可把字符串给转换为整型（最好不使用类型转换）。
    (empty($result) || $result == '-') && $result = 0;   //如果结果为空，或者为负数，按题意则直接赋值为0
    if (is_numeric($result)) {
        $result > pow(2, 31)-1 && $result = pow(2, 31)-1;
        $result < pow(-2, 31) && $result = pow(-2, 31);
    }
    return $result;
}
```

