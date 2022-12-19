class Solution {

    /**
     * @param String $J
     * @param String $S
     * @return Integer
     */
    function numJewelsInStones($J, $S) {
        $num = 0;
        $data = [];
        for($i = 0; $i < strlen($J); $i ++){
            $data[$J[$i]] = 1;
        }

        for($i = 0; $i < strlen($S); $i ++){
            $num += $data[$S[$i]];
        }
        return $num;
    }
}