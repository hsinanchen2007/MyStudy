```
class Solution {

    /**
     * @param Integer[][] $board
     * @return NULL
     */
    function gameOfLife(&$board) {
        for($i=0;$i<count($board);$i++){
            for($j=0;$j<count($board[0]);$j++){
                $board[$i][$j] = $this->helper($board,$i,$j);
            }
        }
        for($i=0;$i<count($board);$i++){
            for($j=0;$j<count($board[0]);$j++){
                if($board[$i][$j] == -1) $board[$i][$j] = 0;
                 else if($board[$i][$j] == -2) $board[$i][$j] = 1;
            }
        }
    }
    
    // -1代表1转0,-2代表0转1
    function helper($board,$i,$j){
        $count = 0;
        $top = max($i-1,0);
        $bottom = min($i+1,count($board)-1);
        $left = max($j-1,0);
        $right = min($j+1,count($board[0])-1);
        for($x=$top;$x<=$bottom;$x++){
            for($y=$left;$y<=$right;$y++){
                $count += ($board[$x][$y]==1||$board[$x][$y]==-1)?1:0;
            }
        }
        // ($count==3||$count==4?1:-1) 由于自身被遍历过一次，所以需+1判断
        return $board[$i][$j]==1 ? ($count==3||$count==4?1:-1) : (($count==3)?-2:0);
    }
}
```
