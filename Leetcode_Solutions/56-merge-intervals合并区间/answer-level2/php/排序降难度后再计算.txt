### 解题思路
先排序即可大大降低难度，具体如下

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $intervals
     * @return Integer[][]
     */
    function merge($intervals) {
        $size = count($intervals);

        //把数组按每一项第一位数排序
        //例如：[[1,3],[2,6],[5,10],[1,9]]排序后为[[1,3],[1,9],[2,6],[5,10]
        //如此只需考虑每一项第一位数跟前一项第二位数的大小关系，即可做出决定
        sort($intervals);

        for($i=1;$i<$size;$i++){
            //如果当前项第一位数小于上一项的第二位
            if($intervals[$i][0] <= $intervals[$i-1][1]) {
                //当前项的第一位数为跟之前项第二个数之中更小的
                $intervals[$i][0] = min($intervals[$i-1][0], $intervals[$i][0]);

                //当前项的第二位数为跟之前项第二个数之中更大的
                $intervals[$i][1] = max($intervals[$i][1], $intervals[$i-1][1]);

                //删除之前项
                unset($intervals[$i-1]);
            }
        }

        return $intervals;
    }
}
```