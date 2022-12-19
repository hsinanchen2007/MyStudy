```
class Solution {

    /**
     * @param String $haystack
     * @param String $needle
     * @return Integer
     */
    function strStr($haystack, $needle) {
        if($needle == ''){return 0;}    // 空字符串返回0
        $len = strlen($haystack);
        $length = strlen($needle);
       
        $i = 0;$j = 0;
        while($i<$len && $j < $length){
            if($haystack[$i] == $needle[$j]){
                $i++;
                $j++;
            }else{
                $i = $i - $j + 1;
                $j = 0;
            }
            if($j == $length){
                return $i-$j;
            }
        }
        return -1;
       
    }
}
```
