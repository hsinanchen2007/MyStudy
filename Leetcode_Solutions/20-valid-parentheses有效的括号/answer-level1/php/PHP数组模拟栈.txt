```
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isValid($s) {
        $phpStack = [];
        $strLen = strlen($s);
        for($i = 0; $i < $strLen; $i++) {
            if($s[$i] == '(' || $s[$i] == '[' || $s[$i] == '{') {
                $phpStack[] = $s[$i];
            }else {
                if(empty($s)) {
                    return false;
                }
                $topChar = array_pop($phpStack);
                if($s[$i] == ')' && $topChar != '(') {
                    return false;
                }
                if($s[$i] == ']' && $topChar != '[') {
                    return false;
                }
                if($s[$i] == '}' && $topChar != '{') {
                    return false;
                }
            }
        }
        
        return $phpStack ? false : true;
    }
}
```