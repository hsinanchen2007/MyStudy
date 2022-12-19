class Solution {

    /**
     * @param Integer $n
     * @return String
     */
    function countAndSay($n)
    {
        if ($n == 1) {
            return '1';
        }
        $value = $this->countAndSay($n - 1);
        $len = strlen($value);
        $lastOne = $value[0];
        $newValue = '';
        $count = 1;
        for ($i = 1; $i < $len; $i++) {
            if ($value[$i] == $lastOne) {
                $count++;
            } else {
                $newValue = $newValue . $count . $lastOne;
                $lastOne = $value[$i];
                $count = 1;
            }
        }
        $newValue = $newValue . $count . $lastOne;
        return $newValue;
    }
}