```
代码块
```
    $len1 = count($arr1);
    $len2 = count($arr2);
    $arr1_v = array_count_values($arr1); // 统计值出现次数

    $res = []; // 在数组中排序
    $row = []; // 保存不在$arr2数组的数据
    
    for ($i = 0; $i< $len2; $i++) {
        foreach ($arr1_v as $key => $value) {
            if ($key == $arr2[$i] && $value == 1) {
                $res[] = $key;
            } else if ($key == $arr2[$i] && $value > 1) {
                for ($k=0; $k < $value; $k++) {
                    $res[] = $key;
                }
            }
        }
    }

    for ($i = 0; $i < $len1; $i++) {
        if (!in_array($arr1[$i], $arr2)) {
            $row[] = $arr1[$i];
        }
    }
        
    if ($row) {
        sort($row);
        $result = array_merge($res, $row);
    } else {
        $result = $res;
    }
    return $result;
```
不知道有没有更好的实现方式，有的请留言