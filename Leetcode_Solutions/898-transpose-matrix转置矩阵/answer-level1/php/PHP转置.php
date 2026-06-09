将数组进行行列遍历
```
class Solution {

    /**
     * @param Integer[][] $A
     * @return Integer[][]
     */
    function transpose($A) {
 
        for($i=0;$i<count($A);$i++){
            
            for($j=0;$j<count($A[$i]);$j++){
                
                $arr[$j][$i]=$A[$i][$j];
            }
        }
        return $arr;
    }
}
```
