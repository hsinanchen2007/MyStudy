class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function orangesRotting($grid) {
        $m = count($grid);
        $n = count($grid[0]);
        $visited = [];
        //将坏橘子推到队列中
        foreach($grid as $lineNum=>$lineData){
            foreach($lineData as $columnNum=>$columnData){
                if($grid[$lineNum][$columnNum] == 2)
                    $queue[] = [$lineNum, $columnNum];
                //初始化已访问元素
                $visited[$lineNum][$columnNum] = false;
            }
        }
        $minute = 0;
        //传染方向
        $directions = [[-1,0], [1,0],[0,-1], [0,1]];
        // var_dump($queue);
        while(true){
            $num = count($queue);
            for($i=0; $i<$num; $i++){
                $bad = array_shift($queue);
                foreach($directions as $direction){
                    $newLine = $bad[0]+$direction[0];
                    $newColumn = $bad[1]+$direction[1];
                    if($newLine >= 0 && $newLine <= $m-1 && $newColumn >= 0 && $newColumn <= $n-1 && !$visited[$newLine][$newColumn] && $grid[$newLine][$newColumn] == 1){
                        $visited[$newLine][$newColumn] = true;
                        $grid[$newLine][$newColumn] = 2;
                        $queue[] = [$newLine, $newColumn];
                    }
                }
            }
            if(empty($queue)) break;
            $minute++;
        }
        foreach($grid as $lineNum=>$lineData){
            foreach($lineData as $columnNum=>$columnData){
                if($grid[$lineNum][$columnNum] == 1)
                    return -1;
            }
        }
        return $minute;
    }
}