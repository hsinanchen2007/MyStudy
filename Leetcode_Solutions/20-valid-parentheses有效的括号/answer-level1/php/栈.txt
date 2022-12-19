```
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isValid($s) {
        if(empty($s))
            return true;
        
        // 搞一个空数组
        $data = [];
        for($i = 0; $i < strlen($s); $i++){
            // 先判断当前括号是否存在
            if($s[$i] == self::getConf()[end($data)]){
                // 出栈
                array_pop($data);
            } else {
                //将当前元素入栈
                array_push($data, $s[$i]);
            }
        }
        
        if($data){
            return false;
        }
        
        return true;
    }
    
    function getConf()
    {
        return [
            '(' => ')',
            '[' => ']',
            '{' => '}'
        ];
    }
}
```
