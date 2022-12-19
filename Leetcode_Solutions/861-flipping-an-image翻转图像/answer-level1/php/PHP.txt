class Solution {

    /**
     * @param Integer[][] $A
     * @return Integer[][]
     */
    function flipAndInvertImage($A) {
        $res = [];
        foreach ($A as $value) {
            $temp = [];
            foreach ($value as $val) {
                if ($val == 0) {
                    $val = 1;
                } else if ($val == 1) {
                    $val = 0;
                }
                array_unshift($temp,$val);
            }
            array_push($res,$temp);
        }
        return $res;
    }
}