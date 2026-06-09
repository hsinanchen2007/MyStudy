```
class NumArray {
    /**
     * @param Integer[] $nums
     */
    function __construct($nums) {
        $this->nums = $nums;
        $this->n = count($nums);
        for ($i = $this->n, $j = 0;  $i < 2 * $this->n; $i++,  $j++)
            $this->tree[$i] = $nums[$j];
        for ($i = $this->n - 1; $i > 0; --$i)
            $this->tree[$i] = $this->tree[$i * 2] + $this->tree[$i * 2 + 1];
    }
  
    /**
     * @param Integer $i
     * @param Integer $val
     * @return NULL
     */
    function update($i, $val) {
        $i += $this->n;
        $this->tree[$i] = $val;
        while($i > 0){
            $left = $i;
            $right = $i;
            if($i%2 == 0){
                $right++;
            }else{
                $left--;
            }
            $i = (int) $i/2;
            $this->tree[$i] = $this->tree[$left] + $this->tree[$right];
        }
    }
  
    /**
     * @param Integer $i
     * @param Integer $j
     * @return Integer
     */
    function sumRange($i, $j) {
        $sum = 0;
        $l = $this->n + $i;
        $r = $this->n + $j;
        while($l <= $r){
            if($l%2 == 1){
                $sum += $this->tree[$l];
                $l++;
            }
            if($r%2 == 0){
                $sum += $this->tree[$r];
                $r--;
            }
            $l = (int) $l/2;
            $r = (int) $r/2;
        }
        return $sum;
    }
}
```
