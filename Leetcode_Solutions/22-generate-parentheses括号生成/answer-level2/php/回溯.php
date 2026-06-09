class Solution {

    public $ret = [];
    /**
     * @param Integer $n
     * @return String[]
     */
    
    function generateParenthesis($n) {
        $left = 0;
        $right = 0;
        $ans = '';
        $this->dfs($n,$left,$right,$ans);
        return $this->ret;
    }

    public function dfs($n,$left,$right,$ans){
        if($left == $n && $right == $n) {
            $this->ret[] = $ans;
            return ;
        }
        
        // 放右括号, 必有左括号
        if($left > $right) {
            $this->dfs($n,$left,$right+1,$ans.')');
        }
        if($left < $n) {
            $this->dfs($n,$left+1,$right,$ans.'(');
        }
        
    }
}