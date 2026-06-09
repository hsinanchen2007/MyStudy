解题思路： 
判断重复，判断标准strpos() ==0 或者不为0 
主要是子串向前移动的距离这个地方容易出错

**是取原来的子串，从重复的脏字符之后的串 加上当前的字符作为新的判断条件。** 

```
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLongestSubstring($s) {
        if(empty($s)){
            return 0;
        }
        $maxSubStrLength = 0;
        $substr = '';
        $substrLength = 0 ;
        for($i=0; $i<strlen($s); $i++){
            if(strpos($substr, $s[$i]) || strpos($substr, $s[$i]) ===0){
                //移动到脏数据的地方
                $substr = substr($substr, strpos($substr, $s[$i])+1) . $s[$i];
                $substrLength = strlen($substr);
            }else{
                $substr.= $s[$i];
                $substrLength ++;
                $substrLength > $maxSubStrLength && $maxSubStrLength = $substrLength;
            }
        }
        return $maxSubStrLength;
    }
}
```
