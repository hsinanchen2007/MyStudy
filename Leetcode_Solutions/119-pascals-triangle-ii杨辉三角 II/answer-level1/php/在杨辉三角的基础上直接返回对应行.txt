```
/**
     * @param Integer $rowIndex
     * @return Integer[]
     */
    function getRow($rowIndex) {
        $res = [];
        for ($i = 0; $i <= $rowIndex; $i++) {
            $tmp = [1];
            for ($j = 0; $j < $i; $j++) {
                if ($j == $i - 1) {
                    $tmp[] = $res[$i - 1][$j];
                } else {
                    $tmp[] = $res[$i - 1][$j] + $res[$i - 1][$j + 1];
                }
            }

            $res[] = $tmp;
        }

        return $res[$rowIndex];
    }
```
