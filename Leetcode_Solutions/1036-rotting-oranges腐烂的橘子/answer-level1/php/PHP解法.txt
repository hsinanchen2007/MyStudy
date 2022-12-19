### 解题思路
参考首页大佬BFS解法讲解，用PHP 数组模拟队列操作。关键点在for循环中的 reset() 一开始用$queue[$i] 取值这样会导致每次循环中$queue的状态一直在变化，所以$queue[$i]并不能保证每次取到准确的值，所以这里用 reset()去除当前数组第一个元素，配合array_shift()模拟队列出栈。

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function orangesRotting($grid) {
        $M = count($grid); //M行
        $N = count($grid[0]); //N列
        $count = 0; //新鲜橘子数量
        $queue = []; //缓存腐烂橘子数据  数组模拟队列
        //先筛选出所有的新鲜橘子和腐烂橘子
        foreach($grid as $key=>$value){
            foreach($grid[$key] as $k=>$v){
                if($v == 1){
                    $count ++;
                }
                if($v == 2){
                    $queue[] = [$key,$k]; //第$key+1行 $k+1列的腐烂橘子
                }
            }
        }
        $round = 0; //腐烂橘子轮数 即分钟数

        while($count > 0 && count($queue) > 0){
            $round ++;
            for($i=0,$size=count($queue);$i<$size;$i++){
                $r = reset($queue)[0]; //腐烂橘子坐标 第$r+1行
                $c = reset($queue)[1]; //腐烂橘子坐标 第$c+1列

                array_shift($queue); //移除队列
                //腐烂橘子 上方
                if($r-1 >= 0 && $grid[$r-1][$c] == 1){
                    $grid[$r-1][$c] = 2;
                    array_push($queue,[$r-1,$c]);
                    $count --;
                }
                //腐烂橘子 下方
                if($r+1 < $M && $grid[$r+1][$c] == 1){
                    $grid[$r+1][$c] = 2;
                    array_push($queue,[$r+1,$c]);
                    $count --;
                }
                //腐烂橘子 左侧
                if($c-1 >= 0 && $grid[$r][$c-1] == 1){
                    $grid[$r][$c-1] = 2;
                    array_push($queue,[$r,$c-1]);
                    $count --;
                }
                //腐烂橘子 右侧
                if($c+1 < $N && $grid[$r][$c+1] == 1){
                    $grid[$r][$c+1] = 2;
                    array_push($queue,[$r,$c+1]);
                    $count --;
                }

            }
        }

        if($count > 0){
            return -1;
        }else{
            return $round;
        }
    }
}
```