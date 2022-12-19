class Solution {

    /**
     * @param Integer[] $digits
     * @return Integer[]
     */
    function plusOne($digits) {
        $digits[count($digits)-1] += 1;
        for ($i = count($digits)-1; $i > 0; $i--) {
            if($digits[$i] == 10){
                $digits[$i] = 0;
                $digits[$i-1] += 1;
            }
        }
        if ($digits[0] == 10) {
            $digits[0] = 0;
            array_unshift($digits,'1');
        }
        return $digits;
    }
}