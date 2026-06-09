class Solution {

    /**
     * @param String $S
     * @return Integer[]
     */
    function diStringMatch($S) {
        $arr = [];
        $m = 0;
        $n = strlen($S);
        for ($i = 0;$i <= strlen($S);$i++) {
            if ($S[$i] == 'I') {
                array_push($arr,$m);
                $m ++;
            } else {
                array_push($arr,$n);
                $n --;
            }
        }
        return $arr;
    }
}