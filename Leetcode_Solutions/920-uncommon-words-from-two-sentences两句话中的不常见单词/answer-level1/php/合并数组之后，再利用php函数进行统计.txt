合并数组之后，利用array_count_values进行统计再输出。

```
class Solution {

    /**
     * @param String $A
     * @param String $B
     * @return String[]
     */
    function uncommonFromSentences($A, $B) {
        
        $result = [];
        $array = explode(' ', $A.' '.$B);
        
        $new_arr = array_count_values($array);
        
        foreach($new_arr as $k => $v){
            if($v == 1){
                $result[] = $k;
            }
            
        }
        return $result;
        
    }
}
```