class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function numDecodings($s) {
        $n=strlen($s);
        $n = strlen($s);
        if ($s == null || $n == 0) {
            return 0;
        }

        $help = 1;
        $res = 0;
        if ($s[$n - 1] != '0') {
            $res = 1;
        }
        for ($i = $n - 2; $i >= 0; $i--) {
            if ($s[$i] == '0') {
                $help = $res;
                $res = 0;
                continue;
            }
        if (($s[$i] - '0') * 10 + ($s[$i + 1] - '0') <= 26) {
            $res += $help;
            //help用来存储res以前的值
            $help = $res-$help;
        } else {
            $help = $res;
        }

        }
        return  $res;
    }
}