class Solution {

    /**
     * @param Integer $x
     * @return Integer
     */
    function reverse($x) {
        $strval = str_split($x);
        $number='';
        if($strval[0]=='-') array_shift($strval);
        for($i=count($strval)-1;$i>=0;$i--){
            $number .= $strval[$i];       
        }
        if($number>pow(2,31)-1 || $number<pow(-2,31)) return 0;
        return (int) $number * ($x<0 ? -1 : 1) ;
    }
}