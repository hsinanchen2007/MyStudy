class Solution {

    /**
     * @param Integer $x
     * @return Integer
     */
    function reverse($x) {
        $btn = 0;
        if ($x < 0) {
            $btn = 1;
        }
        $s = (string) $x;
        $len = strlen($s);
        $str = '';
        for ($i=$len - 1; $i>=0; $i--) {
            $str .= substr($s, $i, 1);
        }

        if ($btn) {
            $res = 0 - (int) $str;
            if ($res < -1*pow(2, 31)) $res = 0;
        } else {
            $res = (int) $str;
            if ($res > pow(2, 31) -1) $res = 0;
        }
        return $res;
    }
}