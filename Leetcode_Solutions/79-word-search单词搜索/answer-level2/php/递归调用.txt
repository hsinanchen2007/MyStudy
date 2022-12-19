### 解题思路
思路都差不多，递归调用。
分享下代码吧，php的。

总结：
1. 递归调用，就是回溯，每次回溯到上一次递归调用处。
2. 递归调用的参数，其实就是回溯点的状态。
3. 回溯本质上用的是栈，递归调用其实就是利用函数栈。

### 代码

```php
class Solution {
    /**
     * @param String[][] $board
     * @param String $word
     * @return Boolean
     */
    function exist($board, $word) {
        for($i=0;$i<count($board);$i++){
            for($j=0;$j<count($board[0]);$j++){
                if($this->dfs($board, $i, $j, $word, 0)){
                    return true;
                }
            }
        }
        return false;
    }
    //返回true，表示从$start开始能通到$word结尾。
    function dfs($board, $i, $j, $word, $start){
        if($i<0 || $j<0 || $i>count($board)-1 || $j>count($board[0])-1){
            return false;
        }

        if($board[$i][$j] != $word[$start]){
            return false;
        }

        if($start == strlen($word)-1){
            return true;
        }

        $board[$i][$j] = '#';

        if($this->dfs($board, $i-1, $j, $word, $start+1)) {
            return true;
        }
        if($this->dfs($board, $i, $j-1, $word, $start+1)) {
            return true;
        }
        if($this->dfs($board, $i+1, $j, $word, $start+1)) {
            return true;
        }
        if($this->dfs($board, $i, $j+1, $word, $start+1)) {
            return true;
        }

        return false;
    }
}






























```