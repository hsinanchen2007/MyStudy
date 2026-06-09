执行用时 :0 ms, 在所有PHP提交中,击败了100.00%的用户内存消耗 :14.7 MB, 在所有PHP提交中击败了48.62%的用户。
class Solution {

    /**
     * @param String $J
     * @param String $S
     * @return Integer
     */
    function numJewelsInStones($J, $S) {
        $bao    = str_split($J);
        $i      = 0;
        foreach($bao as $v){
            $i += substr_count($S,$v);
        }
        return $i;
    }
}