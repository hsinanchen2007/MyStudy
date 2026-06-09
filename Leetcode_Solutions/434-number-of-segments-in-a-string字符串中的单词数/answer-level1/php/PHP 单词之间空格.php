class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function countSegments($s) {
        if(0 ==strlen($s)){
            return 0;
        }
        $count = 0;
        for($i=0;$i<strlen($s);$i++) {
            if($s[$i] !== ' ') {
                $count++;
                while($i<strlen($s)&& $s[$i] !== ' ') {
                    $i++;
                }
            }
        }
        return $count;
    }
}