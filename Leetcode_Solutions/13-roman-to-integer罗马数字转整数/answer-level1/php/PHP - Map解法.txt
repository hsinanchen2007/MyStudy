class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function romanToInt($s) {
        $ret = 0;
        $romanMap = [
            'I' => 1,
            'V' => 5,
            'X' => 10,
            'L' => 50,
            'C' => 100,
            'D' => 500,
            'M' => 1000,
        ];
        $specialRomanMap = [
            'I' => ['V', 'X'],
            'X' => ['L', 'C'],
            'C' => ['D', 'M'],
        ];
        $specialRomanKeys = array_keys($specialRomanMap);
        $len = strlen($s);
        for ($i = 0; $i < $len;$i ++) {
            if ($i < $len-1 && in_array($s[$i], $specialRomanKeys) && in_array($s[$i+1], $specialRomanMap[$s[$i]])) {
                $ret += $romanMap[$s[$i+1]] - $romanMap[$s[$i]];
                $i+=1;
            } else {
                $ret += $romanMap[$s[$i]];
            }
        }
        return $ret;
    }
}