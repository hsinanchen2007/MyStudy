方法一：
    借助临时空间数组作状态参考值，根据条件对原数组修改下一个状态值，优点：简单，易于理解实现。缺点：消耗内存空间
```
class Solution {

    /**
     * @param Integer[][] $board
     * @return NULL
     */
    function gameOfLife(&$board) {
        $tempb = $board;   //临时数组，用于根据周围细胞判断当前细胞是否存活
        $m = count($tempb);
        $n = count($tempb[0]);
        for($i = 0;$i<$m;$i++){
            for($j=0;$j<$n;$j++){
                $thisnum = 0;
                for($a = -1;$a<2;$a++){
                    for($b = -1;$b<2;$b++){
                        if($i + $a < 0 || $i + $a >= $m){
                            break;
                        }
                        if($j + $b < 0 || $j + $b >= $n){
                            continue;
                        }
                        if($a == 0 && $b == 0){
                            continue;
                        }
                        if($tempb[$i + $a][$j + $b] == 1){
                            $thisnum += 1;
                        }
                    }
                }
                if($board[$i][$j] == 1 && ($thisnum < 2 || $thisnum > 3)){
                    $board[$i][$j] = 0;
                }
                if($board[$i][$j] == 0 && $thisnum == 3){
                    $board[$i][$j] = 1;
                }
            }
        }
    }
}
```


方法二：  数组状态原地修改，原状态不变的细胞值不变，死亡细胞变活值改为2，活细胞死亡值改为-1。 优点：节省内存
```
class Solution {

    /**不使用临时数组情况，减少内存使用 各个位置 0 => died, 1 => live,  2 => die to live
     * @param Integer[][] $board
     * @return NULL
     */
    function gameOfLife(&$board) {
        $m = count($board);
        $n = count($board[0]);
        for($i = 0;$i<$m;$i++){
            for($j=0;$j<$n;$j++){
                $thisnum = 0;   //计数,周围活细胞数
                for($a = -1;$a<2;$a++){
                    for($b = -1;$b<2;$b++){
                        if($i + $a < 0 || $i + $a >= $m){
                            break;
                        }
                        if($j + $b < 0 || $j + $b >= $n){
                            continue;
                        }
                        if($a == 0 && $b == 0){
                            continue;
                        }
                        if($board[$i + $a][$j + $b] == 1 ||  $board[$i + $a][$j + $b] == -1){
                            $thisnum += 1;
                        }
                    }
                }
                if($board[$i][$j] == 1&& ($thisnum < 2 || $thisnum > 3)){
                    $board[$i][$j] = -1;  //死亡
                }
                if($board[$i][$j] == 0 && $thisnum == 3){
                    $board[$i][$j] = 2;   //复活使用
                }
            }
        }
        for($i = 0;$i<$m;$i++){
            for($j=0;$j<$n;$j++){
                if($board[$i][$j] > 0){
                    $board[$i][$j] = 1;   //将复活的改回为1
                }else{
                    $board[$i][$j] = 0;
                }
            }
        }
    }
}
```
