```
function addStrings($num1, $num2) {
        // 位数不足的需补0
        $length1 = strlen($num1);
        $length2 = strlen($num2);
        $lack = abs($length1 - $length2);
        if ($length1 < $length2) {
            $num1 = $lack * '0'.$num1;
            $length = $length2;
        } elseif ($length2 < $length1) {
            $num2 = $lack * '0'.$num2;
            $length = $length1;
        } else {
            $length = $length2;
        }
        // 逆转
        $num1Re = strrev($num1);
        $num2Re = strrev($num2);
        $add = 0;
        $result = "";

        for ($i = 0; $i < $length; $i ++ ) {
            $temp = $num1Re[$i] + $num2Re[$i] + $add;
            $result = $result.intval($temp%10);
            $add = intval($temp / 10);
        }
        // 最后一位(即第一位进位需补1)
        if ($add != 0) {
            $result = $result.$add;
        }
        $result = strrev($result);
        return $result;
    }
```
