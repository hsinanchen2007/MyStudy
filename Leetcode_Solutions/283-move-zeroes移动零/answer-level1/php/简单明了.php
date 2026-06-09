```
class Solution {

    /**
     * @param Integer[] $nums
     * @return NULL
     */
    function moveZeroes(&$nums) {
        
        $count = count($nums);
        $j = 0;
        
        for($i = 0; $i < $count; $i++) {
            
            if ($nums[$i]!=0) {
                
                $nums[$j] = $nums[$i];
                
                if ($i != $j) {
                    $nums[$i] = 0; 
                }
                
                $j++;
            }
            
            
            
        }
        
        
    }
}
```
