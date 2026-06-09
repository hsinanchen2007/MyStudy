```

class Solution {
     * @return String
     */
    function removeOuterParentheses($S) {
        $count = 0;
        $result = '';
        for($i = 0 ; $i < strlen($S) ; $i ++){
            if($S[$i] == '('){
                $count++;
                if($i > 0 && $count > 1){
                    $result.=$S[$i];   
                }
            }else{
                $count--;
                if($count > 0){
                    $result.=$S[$i];  
                }
            }
        }
        return $result;
    }
}

```