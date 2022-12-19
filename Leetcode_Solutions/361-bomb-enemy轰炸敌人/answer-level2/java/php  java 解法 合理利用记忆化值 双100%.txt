```php []
function maxKilledEnemies($grid) {
    $m = count($grid);
    $n = count($grid[0]);
    $cols = array_fill(0,$n,0); // 纵向记忆化缓存
    $max = 0;
    for($i=0;$i<$m;$i++){
        $rows = 0; // 横向记忆化缓存
        for($j=0;$j<$n;$j++){
            if($grid[$i][$j]=='0'){
                $total = $rows + $cols[$j]; // 从缓存中获取=向左炸敌人数+向上炸敌人数
                for($k=$j+1;$k<$n && $grid[$i][$k]!='W';$k++){ // 计算向右炸敌人数
                    if($grid[$i][$k]=='E') $total++;
                }
                for($k=$i+1;$k<$m && $grid[$k][$j]!='W';$k++){ // 计算向下炸敌人数
                    if($grid[$k][$j]=='E') $total++;
                }
                $max = max($max,$total);
            }else if($grid[$i][$j]=='W'){
                $rows = 0;
                $cols[$j] = 0;
            }else if($grid[$i][$j]=='E'){
                $rows ++;
                $cols[$j] ++;
            }
        }
    }
    return $max;
}
```
```java []
public int maxKilledEnemies(char[][] grid) {
    if(grid == null || grid.length == 0) return 0;
    int m = grid.length, n = grid[0].length;
    int max = 0;
    int[] cols = new int[n];
    for(int i=0;i<m;i++){
        int rows = 0;
        for(int j=0;j<n;j++){
            if(grid[i][j]=='0'){
                int total = rows + cols[j];
                for(int k=j+1;k<n && grid[i][k]!='W';k++){
                    if(grid[i][k]=='E') total++;
                }
                for(int k=i+1;k<m && grid[k][j]!='W';k++){
                    if(grid[k][j]=='E') total++;
                }
                max = Math.max(max,total);
            }else if(grid[i][j]=='W'){
                rows = 0;
                cols[j] = 0;
            }else if(grid[i][j]=='E'){
                rows ++;
                cols[j] ++;
            }
        }
    }
    return max;
}
```
