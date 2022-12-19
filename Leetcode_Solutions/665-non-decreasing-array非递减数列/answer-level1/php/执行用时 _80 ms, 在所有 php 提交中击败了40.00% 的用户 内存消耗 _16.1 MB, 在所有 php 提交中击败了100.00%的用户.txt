```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Boolean
     */
    function checkPossibility($nums) {
        $count =0;
        for($i= 0;$i<count($nums)-1;$i++){
            if($nums[$i] > $nums[$i+1]){
                if($i== 0 || $nums[$i-1]<=$nums[$i+1]){
                    $nums[$i] = $nums[$i+1];
                }else{
                     $nums[$i+1] = $nums[$i];
                }
                $count++;
                if($count == 2){
                   return false;
                }
            }
        }
        return true;
    }
}
```
