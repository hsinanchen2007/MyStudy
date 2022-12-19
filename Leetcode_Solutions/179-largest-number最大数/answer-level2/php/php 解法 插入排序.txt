```
class Solution {

    /**
     * @param Integer[] $nums
     * @return String
     */
    function largestNumber($nums) {
        for($i=1;$i<count($nums);$i++){
            for($j=$i;$j>0;$j--){
                if((int) $nums[$j].$nums[$j-1] > (int) $nums[$j-1].$nums[$j]){
                    $this->swap($nums,$j,$j-1);
                }
            }
        }
        if($nums[0]=="0") return "0";
        return implode("",$nums);
    }
    
    function swap(&$arr,$i,$j){
        $temp = $arr[$i];
        $arr[$i] = $arr[$j];
        $arr[$j] = $temp;
    }
}
```
