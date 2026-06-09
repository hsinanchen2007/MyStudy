### 解题思路
此处撰写解题思路
本题有两个要求，第一判断是否能全部腐烂；第二判断全部感染最少时间；所以本题需要两个变量来存储，第一个是感染个数和橘子个数比较；第二个则是感染的橘子；由于感染有先后，符合队列条件，所以把每分钟感染橘子的位置放到队列中。
1. 遍历grid，拿到0分钟时，也即初始状态腐烂橘子的位置，放入队列中；构造的队列是step=>[[row,col]]格式，此时将grid该位置置为3.
2. 处理队列，计数的同时，上下左右遍历==1的也即正常的橘子，将其加入队列，等同于感染
3. 终止条件是，队列中不再有橘子
4. 
### 代码

```php
class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function orangesRotting($grid) {
        //找到腐烂的橘子
        //能够遍历的最少步数
        //队列计数
        $arrQueue = [];
        $count = 0;
        foreach ($grid as $row => $arrRow) {
            foreach ($arrRow as $col => $value) {
                if ($value == 2) {
                    $arrQueue[0][] = [$row, $col];
                    $grid[$row][$col] = 3;
                }
                if ($value != 0) {
                    $count ++;
                }
            }
        }

        if (!isset($arrQueue[0])) {
            if ($count > 0) {
                return -1;
            }
            return 0;
        }
        $step = 0;
        $rowCount = count($grid);
        $colCount = count($grid[0]);
        $newCount = 0;
        while (isset($arrQueue[$step])) {
            //上下左右四个方向遍历
            while ($arr = array_shift($arrQueue[$step])) {
                
                $newCount ++;
                //上
                if ($arr[0] > 0 && $grid[$arr[0] - 1][$arr[1]] == 1) {
                    $arrQueue[$step + 1][] = [$arr[0] - 1, $arr[1]];
                    $grid[$arr[0] - 1][$arr[1]] = 3;
                }
                //下
                if ($arr[0] < $rowCount - 1 && $grid[$arr[0] + 1][$arr[1]] == 1) {
                    $arrQueue[$step + 1][] = [$arr[0] + 1, $arr[1]];
                    $grid[$arr[0] + 1][$arr[1]] = 3;
                }
                //左
                if ($arr[1] > 0 && $grid[$arr[0]][$arr[1] - 1] == 1) {
                    $arrQueue[$step + 1][] = [$arr[0], $arr[1] - 1];
                    $grid[$arr[0]][$arr[1] -1] = 3;
                }
                //右
                if ($arr[1] < $colCount - 1 && $grid[$arr[0]][$arr[1] + 1] == 1) {
                    $arrQueue[$step + 1][] = [$arr[0], $arr[1] + 1];
                    $grid[$arr[0]][$arr[1] + 1] = 3;
                }


                //$grid[$arr[0]][$arr[1]] = 3;
            }

            $step ++;


        }
        if ($count == $newCount) {
            return $step - 1;
        }
        return -1;
        //return $step - 1;
    }
}
```