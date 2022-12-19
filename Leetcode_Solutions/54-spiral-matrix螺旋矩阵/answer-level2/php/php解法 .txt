首先确定上下左右四条边的位置
顺时针螺旋取值过程中，不断缩小边界值
```
function spiralOrder($matrix) {
    $ans = [];
    $depth = count($matrix);
    $len = count($matrix[0]);
    // 确定上下左右四条边的位置
    $up = 0;
    $down = $depth-1;
    $left = 0;
    $right = $len-1;
    while(true){
        for($i = $left; $i <= $right; $i++) $ans[] = $matrix[$up][$i];
        if(++$up > $down) break;
        for($i = $up; $i <= $down; $i++) $ans[] = $matrix[$i][$right];
        if(--$right < $left) break;
        for($i = $right; $i >= $left; $i--) $ans[] = $matrix[$down][$i];
        if(--$down < $up) break;
        for($i = $down; $i >= $up; $i--) $ans[] = $matrix[$i][$left];
        if(++$left > $right) break;
    }
    return $ans;
}
```
