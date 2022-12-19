### 解题思路
感谢[@holiwood](/u/holiwood/)的解题

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function orangesRotting($grid) {
        //总回合数
        $rounds = 0;
        //烂橘子组
        $bad_ojs = [];

        //格子的x轴长度
        $rows = count($grid);
        //格子的y轴长度
        $cols = count($grid[0]);

        //先找出已经被感染的橘子，加入烂橘子组，x轴，y轴，回合数记做0
        for($i=0;$i<$rows;$i++){
            for($j=0;$j<$cols;$j++){
                if($grid[$i][$j] == 2){
                    $bad_ojs[] = [$i, $j, 0];
                }
            }
        }

        //可感染的坐标
        $spread_x = [1,-1,0,0];
        $spread_y = [0,0,1,-1];

        //如果当前还有烂橘子可以去传染
        while(!empty($bad_ojs)){
            $top_bad_oj = array_shift($bad_ojs);
            for($i=0;$i<4;$i++){
                //感染橘子的四周坐标
                $new_oj_x = $top_bad_oj[0] + $spread_x[$i];
                $new_oj_y = $top_bad_oj[1] + $spread_y[$i];

                //感染橘子的回合数
                $cur_round = $top_bad_oj[2];

                //传染新鲜橘子
                if($grid[$new_oj_x][$new_oj_y] == 1){
                    $grid[$new_oj_x][$new_oj_y] = 2;
                    //把感染的橘子加入感染队列
                    $bad_ojs[] = [$new_oj_x, $new_oj_y, $cur_round+1];
                    //更新回合数
                    $rounds = max($rounds,$cur_round+1);
                }
            }
        }

        //遍历方格，如果还有新鲜的橘子，代表有不能被污染的橘子，返回-1
        for($i=0;$i<$rows;$i++){
            for($j=0;$j<$cols;$j++){
                if($grid[$i][$j] == 1) return -1;
            }
        }

        return $rounds;
    }
}
```