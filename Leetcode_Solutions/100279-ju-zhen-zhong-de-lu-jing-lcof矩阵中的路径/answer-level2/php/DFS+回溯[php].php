### 解题思路
这道题目是对矩形进行搜索，其实就是DFS。
当然，DFS的过程中肯定有不对的，那这时候就需要回溯。
所以是DFS+回溯解这个问题，具体思路见代码注释。

### 代码

```php
class Solution {
    /**
     * @param String[][] $board
     * @param String $word
     * @return Boolean
     */
    function exist($board, $word) {
        $row_count = count($board);
        $column_count = count($board[0]);
        $res=[];
        $max_step = strlen($word) - 1;
        for ($i=0;$i<$row_count;$i++){
            for($j=0;$j<$column_count;$j++){
                $this->helper($board,$i,$j,$word,0,$max_step,[],$res);
            }
        }
        if(count($res) == strlen($word)){
            return true;
        }
        return false;
    }

    function helper($board,$i,$j,$word,$step,$max_step,$selected,&$res){
        //数组越界、超出层级、已经选取过该字母、目标字母不匹配、匹配完成 都返回
        if(!isset($board[$i][$j]) || $max_step<$step || isset($selected[$i][$j]) || $board[$i][$j] != $word[$step] || count($res)==strlen($word)){
            return ;
        }
        if($board[$i][$j] == $word[$step]){
            //每一次回溯都把错误的数据置空
            $res = array_slice($res,0,$step);
            array_push($res,$word[$step]);

            //记录已经使用的字母的位置
            $selected[$i][$j]=1;
        }

        //上下左右都尝试
        return ($this->helper($board,$i-1,$j,$word,$step+1,$max_step,$selected,$res))||
            ($this->helper($board,$i+1,$j,$word,$step+1,$max_step,$selected,$res))||
            ($this->helper($board,$i,$j-1,$word,$step+1,$max_step,$selected,$res))||
            ($this->helper($board,$i,$j+1,$word,$step+1,$max_step,$selected,$res));
    }
}
```