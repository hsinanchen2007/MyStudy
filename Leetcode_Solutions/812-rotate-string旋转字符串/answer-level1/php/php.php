class Solution {

    /**
     * @param String $A
     * @param String $B
     * @return Boolean
     */
    function rotateString($A, $B) {
        $c = strlen($A);
        if($A == $B)
        {
            return true;
        }
        while($c != 0)
        {   
            $arr1 = str_split($A);
            $str1 = $arr1[0];
            array_shift($arr1);
            array_push($arr1,$str1);
            $A = implode($arr1);
            if($A == $B)
            {
                return true;
            }
            $c--;
        }
        return false;
    }
}