class Solution {

    /**
     * @param String $s
     * @return String
     */
    function decodeString($s) {
        return $this->amaze($s, 0);
    }



    function amaze($s, $i)
    {
        $len = strlen($s);
        $multi = 0;
        $res = '';
        while ($i < $len) {
            if ($s[$i] == '[') {
                list($i, $tmp) = $this->amaze($s, $i+1);
                for ($k=0; $k < $multi; $k++) {
                    $res .= $tmp;
                }
                $multi = 0;
            } elseif ($s[$i] == ']') {
                return [$i, $res];
            } elseif ((intval($s[$i]) > 0) || $s[$i] == '0') {
                $multi = $multi * 10 + intval($s[$i]);
            } else {
                $res .= $s[$i];
            }
            $i++;

        }

        return $res;

    }

   
}