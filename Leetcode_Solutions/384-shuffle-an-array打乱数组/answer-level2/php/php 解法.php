```
class Solution {
    /**
     * @param Integer[] $nums
     */
    function __construct($nums) {
        $this->ori = $nums;
        $this->arr = $this->ori;
    }

    private $arr;
    private $ori;
  
    /**
     * Resets the array to its original configuration and return it.
     * @return Integer[]
     */
    function reset() {
        $this->arr = $this->ori;
        return $this->arr;
    }
  
    /**
     * Returns a random shuffling of the array.
     * @return Integer[]
     */
    function shuffle() {
        $n = count($this->arr);
        for($i=0;$i<$n;$i++){
            $random = rand($i,$n-1);
            $this->swap($i,$random);
        }
        return $this->arr;
    }

    function swap($i,$j){
        $tmp = $this->arr[$i];
        $this->arr[$i] = $this->arr[$j];
        $this->arr[$j] = $tmp;
    }
}
```
