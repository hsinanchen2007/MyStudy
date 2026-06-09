class Solution {

    /**
     * @param String $str
     * @return Integer
     */
    function myAtoi($str) {
        preg_match('/^[\+\-]?\d+/',trim($str),$strval);
        if(count($strval)==0) return 0;
        $intval = (Integer) $strval[0];
        if($intval>=2147483647) return 2147483647;
        if($intval<=-2147483648) return -2147483648;
        return $intval;
    }
}