# 最初版
// 内存消耗好大，请大佬指导优化点
```
    function plusOne($digits) {
        $counts = count($digits);
        for ($i = count($digits)-1; $i >= 0; --$i) {
            if ($digits[$i] == 9) {
                $digits[$i] = 0;
            } else {
                $digits[$i] += 1;
                break;
            }
        }
        if ($digits[0] == 0) {
            array_unshift($digits, 1);
        }
        return $digits;
    }

```
