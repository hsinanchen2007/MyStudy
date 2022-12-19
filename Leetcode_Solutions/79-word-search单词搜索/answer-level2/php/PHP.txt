
```php
   /**
     * @param String[][] $board
     * @param String $word
     * @return Boolean
     */
    function exist($board, $word) {
        if(empty($board) || empty($board[0])) return false;
        
        for($i=0;$i<count($board);$i++){
            for($j=0;$j<count($board[0]);$j++){
                if($this->helper($board,$word,0,$i,$j,$visited[$i][$j])) return true;
            
            }
        }
        return false;
    }
    
    function helper($board,$word,$index,$row,$col, &$visited){
        //找到匹配的单词
        if($index==strlen($word)) return true; 
        
        //边界的处判断以及 当前行列对应值是否和匹配的当前位置字符串相等
       if($row<0 || $col <0 || $row >= count($board) || $col>=count($board[0]) 
          || $visited[$row][$col] || $board[$row][$col] != $word[$index] ) return false;
       
        $visited[$row][$col]=true;
        //递归调用下一个需要匹配的四个方向行列位置的变化
        if($this->helper($board,$word,$index+1,$row-1,$col,$visited)  || $this->helper($board,$word,$index+1,$row+1,$col,$visited) 
           || $this->helper($board,$word,$index+1,$row,$col-1,$visited) || $this->helper($board,$word,$index+1,$row,$col+1,$visited)) return true;
        
        //此路不通爷回退
        $visited[$row][$col]=false;
    
        return false;
       
    }
```
  