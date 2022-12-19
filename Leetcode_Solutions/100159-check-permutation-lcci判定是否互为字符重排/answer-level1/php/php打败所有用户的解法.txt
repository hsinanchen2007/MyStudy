思路很简单，就是先拆分成数组，然后通过value排序，再拼接成字符串
然后对比2个字符串

function CheckPermutation($s1, $s2) {
    $arr = str_split($s1);
    asort($arr);
    $str1 = implode('', $arr);
    $arr2 = str_split($s2);
    asort($arr2);
    $str2 = implode('', $arr2);
    return $str1 == $str2;
}