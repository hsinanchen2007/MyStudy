### 解题思路
小白木有思路，修改了甜姨的Java代码，结果执行的时候经常会超出时间限制。
哭泣😢
### 代码

```php
class Solution {

    /**
     * @param Integer[][] $grids
     * @return Integer
     */
    function maxDistance($grids) {
        $dx = [0, 0, 1, -1];
        $dy = [1, -1, 0, 0];

        $queue = [];
        // grids length
        $len = count($grids);
        $item_len = count($grids[0]);
        // 把所有陆地入队列
        for($i = 0; $i < $len; ++$i) {
            for($j = 0; $j < $len; ++$j ) {
                if($grids[$i][$j] === 1) {
                    array_unshift($queue, [$i, $j]);
                }
            }
        }

        // 从各个陆地开始一圈圈遍历海洋，最后遍历到的海洋就是离陆地最远的海洋
        $hasOcean = false;
        $point = null;
        while(!empty($queue)) {
            $point = $queue[count($queue)-1];
            $x = $point[0];
            $y = $point[1];
            // var_dump($queue);
            // var_dump($x);
            // var_dump($y);
            array_pop($queue);
            // 取出队列的陆地元素，将其四周(上下左右)的海洋入队列
            for($i = 0; $i < 4; ++$i) {
                $newX = $x + $dx[$i];
                $newY = $y + $dy[$i];
                if($newX < 0
                || $newX >= $len
                || $newY < 0
                || $newY >= $item_len
                || $grids[$newX][$newY] !== 0) {
                    continue;
                }
                 // 这里直接修改原数组，就不需要额外的数组来标志是否访问
                $grids[$newX][$newY] = $grids[$x][$y] + 1;
                $hasOcean = true;
                array_unshift($queue, [$newX, $newY]);
            }
        }
        // 没有陆地或者没有海洋，直接return -1
        if($point == null || !$hasOcean) {
            return -1;
        }

        // 返回最后一次=遍历到的海洋的距离
        return $grids[$point[0]][$point[1]] - 1;
    }
}
```