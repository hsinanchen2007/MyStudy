```
class Solution {
    /**
     * @param Integer[] $nums
     */
    function __construct($nums) {
        $this->arr = $nums;
    }
    
    private $arr;
    /**
     * @param Integer $target
     * @return Integer
     */
    function pick($target) {
        $r = rand();
        $n = 0;
        $index = 0;
        for($i=0;$i<count($this->arr);$i++){
            if($this->arr[$i] == $target){
                $n++;
                if($r%$n==0) $index = $i;
            }
        }
        return $index;
    }
}
```
