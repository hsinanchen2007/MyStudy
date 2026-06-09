```
function reverseStr($s, $k)
    {
        $total = $single = '';
        $arr = str_split($s, $k*2);

        foreach ($arr as $key => $value) {
            $len = strlen($value);
            if ($len < $k) {
                $single = strrev($value);
//            } else if ($len < $k*2 || $len >= $k) {
//                $singArr = str_split($value, $k);
//                $single = strrev($singArr[0]) . $singArr[1];
            } else {
                $singArr = str_split($value, $k);
                $single = strrev($singArr[0]) . $singArr[1];
            }
            $total .= $single;
        }

        return $total;
    }
```
