```
class Solution {

    /**
     * @param Integer[] $nums
     * @return NULL
     */
    function nextPermutation(&$nums) {
        $i = count($nums)-2;
        while($i>=0 && $nums[$i+1]<=$nums[$i]){
            $i--;
        }
        if($i>=0){
            $j = count($nums)-1;
            while($j>=0 && $nums[$j]<=$nums[$i]){
                $j--;
            }
            $this->swap($nums,$i,$j);
        }
        $this->reverse($nums,$i+1);
    }
    
    private function reverse(&$nums, $start){
        $i = $start;
        $j = count($nums)-1;
        while($i<$j){
            $this->swap($nums,$i,$j);
            $i++;
            $j--;
        }
    }
    
    private function swap(&$nums, $i, $j){
        $tmp = $nums[$i];
        $nums[$i] = $nums[$j];
        $nums[$j] = $tmp;
    }
}
```
