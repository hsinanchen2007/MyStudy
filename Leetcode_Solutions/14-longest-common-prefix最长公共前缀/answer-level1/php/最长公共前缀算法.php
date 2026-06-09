```
function prefix($arr) {
    <!-- $arr = ['abcdwf', 'abcdddee', 'abcdee', 'abcdq']; -->
    $count = count($arr); // 数组长度
    $minx = 0; // 默认第一个值为最小
    $min_str = $arr[$minx]; // 最小值
    $minlen = strlen($min_str); // 最小值长度
    // 找出最小值键
    for($i = 1; $i < $count; $i++) {
        if (strlen($arr[$i]) < $minlen) {
            $minx = $i;
        }
    }

    $min_str = $arr[$minx];
    unset($arr[$minx]); // 删除数组中最小的那个值
    sort($arr); // 重新排序
    $minlen = strlen($min_str);
    $res = ''; 
    // 用最小值每个字符去剩下的数组中每个值循环判断
    for ($j = 0; $j < $minlen; $j++) { // 循环最下字符串
        for ($x = 0; $x < count($arr); $x++) { // 循环数组
            if ($min_str[$j] != $arr[$x][$j]) {  // 判断值是否相等
                return $res;
            }
        }

        $res .= $min_str[$j]; // 追加到结果集中
    }

    return $res;
}
```
