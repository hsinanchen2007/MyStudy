class Solution {

    /**
     * @param Integer $n
     * @return Boolean
     */
    function isPowerOfThree($n) {
        if($n <= 1)
        {
            if($n == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        $n = $n/3;
        return $this->isPowerOfThree($n);
    }
}