`class Solution {

    /**
     * @param Integer $num
     * @return Boolean
     */
    function isPerfectSquare($num) {
        if($num == 1){
            return true;
        }
        $left = 2;
        $right = (int)($num/2);
        while($left <= $right){
            $mid = $left + (int)(($right - $left)/2);
            $ji = $mid * $mid;
            if($ji == $num){
                return true;
            }elseif($ji < $num){
                $left = $mid + 1;
            }else{
                $right = $mid - 1;
            }
        }
        return false;
    }
}`