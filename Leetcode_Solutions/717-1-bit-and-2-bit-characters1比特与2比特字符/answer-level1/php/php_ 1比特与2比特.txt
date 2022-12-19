
* 只有0，10，11三种情况出现，
* 即如果从第一位开始，
*   当前是0，则往后移动一位，在这期间到头了，则为true
*   当前是1，往后移动2位，在这期间到头了，则为true

```
代码块
class Solution {
    /**
     * @param Integer[] $bits
     * @return Boolean
     */
    function isOneBitCharacter($bits) {
        $i = 0;
        while($i<count($bits)){
            if( $bits[$i] ==0 ){
                $i++;
                if($i>=$count){
                    return true;
                }
            }else{
               $i+=2;
                if($i>=$count){
                    return false;
                } 
            }
        }
    }
}
```

