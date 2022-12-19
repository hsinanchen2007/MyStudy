class Solution {

    /**
     * @param Integer[] $stones
     * @return Integer
     */
    function lastStoneWeight($stones) {
        if(count($stones) <= 1)
        {
            return $stones?$stones[0]:0;
        }
        rsort($stones);
        $num1 = $stones[0];
        $num2 = $stones[1];
        array_shift($stones);
        array_shift($stones);
        if($num1 != $num2)
        {
            array_push($stones,($num1-$num2));
        }
        return $this->lastStoneWeight($stones);
    }
}