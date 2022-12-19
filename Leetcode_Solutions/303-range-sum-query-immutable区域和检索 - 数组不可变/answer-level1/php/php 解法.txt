```
class NumArray {
    /**
     * @param Integer[] $nums
     */
    function __construct($nums) {
        $this->num = $nums;
        $this->sum = [];
        $this->sum[0] = $nums[0];
        for($i=1;$i<count($nums);$i++){
            $this->sum[$i] = $this->sum[$i-1] + $nums[$i];
        }
    }
  
    /**
     * @param Integer $i
     * @param Integer $j
     * @return Integer
     */
    function sumRange($i, $j) {
        if($i==0){
            return $this->sum[$j];
        }else{
            return $this->sum[$j] - $this->sum[$i] + $this->num[$i];
        }
    }
}
```
