题解：弄个左右括号对应字典，排除空字符和单个括号，然后从左边开始一个一个遍历括号，和栈中的做对比

class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isValid($s) {
        $stack = new SplStack();

        $len = strlen($s);
        $strConfig = ['('=>')','['=>']','{'=>'}'];
        if(empty($s)) return true;
        if($len % 2 != 0) return false;

        for($i=0;$i<$len; $i++){
            if(array_key_exists($s[$i],$strConfig)){
                $stack->push($strConfig[$s[$i]]);
            }elseif($stack->isEmpty() || $s[$i] != $stack->pop()){
                return false;
            }
        }

        return $stack->isEmpty();
    }
}