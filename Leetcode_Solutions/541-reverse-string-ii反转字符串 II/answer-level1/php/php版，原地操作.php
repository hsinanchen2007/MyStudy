```
class Solution {

    /**
     * @param String $s
     * @return String
     */
    function reverseStr($s, $k) {
        $len = strlen($s);
        $doubleK = $k << 1;
        for ($i=0; $i < $len; $i++) { 
            $base = ($i + 1);
            if ($base % $doubleK === 0) {
                $start = $base - $doubleK;
                $end = $base - $k;
                $this->reverse($s, $start, $end);
            }
        }
        $mod = $i % $doubleK;
        if ($mod &&   $mod < $k) {

            $base = $mod;
            $start = $i - $base;
            $end = $i;
            $this->reverse($s, $start, $end);
        } elseif ($mod >= $k) {

            $base = $mod;
            $start = $i - $base;
            $end = $start + $k;
             
            $this->reverse($s, $start, $end);
        }
        return $s;
    }
    private function reverse(&$s, $start, $end) {
        for ($i=$start, $j = $end - 1; $i < $j; $i++, $j--) { 
            [$s[$i], $s[$j]] = [$s[$j], $s[$i]];
        }
    }
}
```