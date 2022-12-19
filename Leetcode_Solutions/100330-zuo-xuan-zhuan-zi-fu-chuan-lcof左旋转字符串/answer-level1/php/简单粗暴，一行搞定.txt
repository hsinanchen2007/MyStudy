class Solution {

    /**
     * @param String $s
     * @param Integer $n
     * @return String
     */
    function reverseLeftWords($s, $n) {

        return substr($s,$n).substr($s,0,$n);

    }
}