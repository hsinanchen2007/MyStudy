最初的想法，是全排列，然后随便返回一个排列完的数组。天真了。超时过不去。

##洗牌

说是mt_rand 比 rand 快4倍。
```
class Solution {
    private $nums = [];
    private $originNums = [];
        
    /**
     * @param Integer[] $nums
     */
    function __construct($nums) {
        $this->nums = $nums;
        $this->originNums= $nums;
    }
  
    /**
     * Resets the array to its original configuration and return it.
     * @return Integer[]
     */
    function reset() {
        $this->nums  = $this->originNums;
        return $this->nums;
    }
  
    /**
     * Returns a random shuffling of the array.
     * @return Integer[]
     */
    function shuffle() {
    	$count = count($this->originNums);

        for ($i=0; $i < $count; $i++) { 
        	 $randIndex = mt_rand($i, $count - 1);
        	 if ($randIndex !== $i) {
        	 	[$this->nums[$randIndex], $this->nums[$i]] = [$this->nums[$i], $this->nums[$randIndex]];
        	 }
        }
        return $this->nums;
    }

}

```