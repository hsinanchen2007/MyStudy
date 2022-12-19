解法提示：
依次列举n=1,n=2,n=3的情况，基本可以知道结果是一个有条件的树状结构，所以就可以用回溯来解。

ps：解题时打的草稿(有点丑)
![微信图片_20190827181624.jpg](https://pic.leetcode-cn.com/4c07ab1b35356809cbb5fdfbc687cc52d7073520a408aa54204eed7c6b0634f2-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20190827181624.jpg)

```
class Solution {
    
    public $ansList = []; 
    /**
     * @param Integer $n
     * @return String[]
     */
    function generateParenthesis($n) {
        $this->backtrack("",0,0,$n);
        return $this->ansList;
    }
    
    function backtrack($ans,$open,$close,$n){
        if($open==$n && $close==$n){
            $this->ansList[] = $ans;
            return ;
        }
        if($open<$n) $this->backtrack($ans."(",$open+1,$close,$n);
        if($close<$open) $this->backtrack($ans.")",$open,$close+1,$n);
    }
}
```
