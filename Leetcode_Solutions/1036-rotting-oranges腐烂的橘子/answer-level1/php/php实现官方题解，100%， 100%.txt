
```
class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function orangesRotting($grid) {
      $ans = 0;
      
      $queue = [];
      //找出所有的腐烂的橘子，先加入队列
      $rowCount = count($grid);
      $colCount = count($grid[0]);
      
      for ($r = 0; $r < $rowCount; $r++) {
        for ($c = 0; $c < $colCount; $c++) {
          if ($grid[$r][$c] == 2) {
            $queue[] = [$r, $c, 0]; //行号，列号，深度，初始深度是0(因为已经腐烂的橘子没有花费任何时间)
          }
        }
      }
      
      $rowOffsets = [-1, 1, 0, 0];
      $colOffsets = [0, 0, -1, 1];
      //使用广度优先搜索
      while (!empty($queue)) {
        $currentOrange = array_shift($queue);//出队列
        
        //遍历当前橘子上下左右的橘子，如果有新鲜的，将该橘子污染，并将其入队列，深度在当前橘子基础上加1
        for ($i = 0; $i < 4; $i++) {
          $newOrangeRow = $currentOrange[0] + $rowOffsets[$i];
          $newOrangeCol = $currentOrange[1] + $colOffsets[$i];
          
          if ($grid[$newOrangeRow][$newOrangeCol] == 1) {
            $grid[$newOrangeRow][$newOrangeCol] = 2;
            
            $newDepth = $currentOrange[2] + 1;
            $queue[] = [$newOrangeRow, $newOrangeCol, $newDepth];
            
            if ($newDepth > $ans) {
              $ans = $newDepth; 
            } 
          }
        }
      }
      
      //遍历方格，如果还有新鲜的橘子，代表有不能被污染的橘子，返回-1
      for ($r = 0; $r < $rowCount; $r++) {
        for ($c = 0; $c < $colCount; $c++) {
          if ($grid[$r][$c] == 1) {
            return -1;
          }
        }
      }
      
      return $ans;
    }
}
```
