```
class TicTacToe {
    /**
     * Initialize your data structure here.
     * @param Integer $n
     */
    function __construct($n) {
        $this->rows = array_fill(0,2,array_fill(0,$n,0));
        $this->cols = array_fill(0,2,array_fill(0,$n,0));;
        $this->diag1 = [0,0]; // 对角线\
        $this->diag2 = [0,0]; // 对角线/
        $this->n = $n;
    }
  
    /**
     * Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins.
     * @param Integer $row
     * @param Integer $col
     * @param Integer $player
     * @return Integer
     */
    function move($row, $col, $player) {
        $id = $player-1;
        $this->rows[$id][$row]++;
        $this->cols[$id][$col]++;
        if($row == $col){
            $this->diag1[$id]++;
        }
        if($row + $col == $this->n -1){
            $this->diag2[$id]++;
        }
        if($this->rows[$id][$row] == $this->n 
            || $this->cols[$id][$col] == $this->n 
            || $this->diag1[$id] == $this->n 
            || $this->diag2[$id] == $this->n){
            return $player;
        }
        return 0;
    }
}
```
