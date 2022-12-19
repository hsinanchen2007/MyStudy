
看着挺绕的，但其实只要复制出另一个矩阵，在新矩阵的基础上遍历旧矩阵的数据根据条件修改值即可
```
function gameOfLife(&$board) {
        $newBoard = $board;
        for ($i=0; $i < count($board); $i++) { 
            for ($j=0; $j < count($board[$i]); $j++) { 
                $liveNum = 0;
                $dieNum = 0;
                //左上角
                if (isset($board[$i-1][$j-1])) {
                    if ($board[$i-1][$j-1] == 1) {
                        $liveNum ++ ;
                    }else{
                        $dieNum ++ ;
                    }
                }
                //上面
                if (isset($board[$i-1][$j])) {
                    if ($board[$i-1][$j] == 1) {
                        $liveNum ++ ;
                    }else{
                        $dieNum ++ ;
                    }
                }
                //右上角
                if (isset($board[$i-1][$j+1])) {
                    if ($board[$i-1][$j+1] == 1) {
                        $liveNum ++ ;
                    }else{
                        $dieNum ++ ;
                    }
                }
                //左边
                if (isset($board[$i][$j-1])) {
                    if ($board[$i][$j-1] == 1) {
                        $liveNum ++ ;
                    }else{
                        $dieNum ++ ;
                    }
                }
                //右边
                if (isset($board[$i][$j+1])) {
                    if ($board[$i][$j+1] == 1) {
                        $liveNum ++ ;
                    }else{
                        $dieNum ++ ;
                    }
                }
                //左下角
                if (isset($board[$i+1][$j-1])) {
                    if ($board[$i+1][$j-1] == 1) {
                        $liveNum ++ ;
                    }else{
                        $dieNum ++ ;
                    }
                }
                //右下角
                if (isset($board[$i+1][$j+1])) {
                    if ($board[$i+1][$j+1] == 1) {
                        $liveNum ++ ;
                    }else{
                        $dieNum ++ ;
                    }
                }
                //下面
                if (isset($board[$i+1][$j])) {
                    if ($board[$i+1][$j] == 1) {
                        $liveNum ++ ;
                    }else{
                        $dieNum ++ ;
                    }
                }
                //判断当前旧矩阵的是活细胞还是死细胞
                switch ($board[$i][$j]) {
                    case 0://死细胞根据条件激活，新矩阵修改
                        if ($liveNum == 3) {
                            $newBoard[$i][$j] = 1;
                        }
                        break;
                    case 1://活细胞根据条件变化
                        if ($liveNum < 2 || $liveNum > 3) {
                            $newBoard[$i][$j] = 0;
                        }
                        if ($liveNum == 2 || $liveNum == 3) {
                            # 不变
                        }
                        break;
                }
            }
        }
        //重中之重，要重新赋值，不然过不了
        $board = $newBoard;
        return $newBoard ;
    }
```
