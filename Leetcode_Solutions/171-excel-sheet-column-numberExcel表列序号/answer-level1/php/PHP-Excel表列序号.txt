class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function titleToNumber($s) {
        $len = strlen($s);
        $ret = 0;
        //ABB = A*26*26 + B*26 + B
        for ($i = 0; $i < $len; $i++) {
            $ret += (ord($s[$i])-64) * pow(26, $len-$i-1);
        }
        return $ret;
    }
}