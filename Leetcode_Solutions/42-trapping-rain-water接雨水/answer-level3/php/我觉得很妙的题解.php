一开始没什么思路，看了下评论，有题友写了个很妙的思路，感觉很nice

**思路：**
1、找出柱子的最高点，分左右两边进行遍历
2、如果当前柱子比上一个柱子矮的话，则说明可以蓄水
3、注意连续柱子变矮的情况

**实现**
```php []
class Solution {

    /**
     * @param Integer[] $height
     * @return Integer
     */
    function trap($height) {
        $water = 0;
        $len = count($height);
        $max_h = 0;
        $max_index = 0;
        //找出最高的柱子及其在数组中的索引下标
        for($i = 0;$i < $len;$i++){
            if($height[$i] >= $max_h){
                $max_h = $height[$i];
                $max_index = $i;
            }
        }
        //计算最高柱子左侧的蓄水量
        $left_index = 0;  //记录左边的最高挡水位置
        for($i=1;$i<$max_index;$i++){
            if($height[$i - 1]>=$height[$left_index]){
                $left_index = $i - 1;
            }
            if($height[$i] < $height[$left_index]){
                $water += $height[$left_index] - $height[$i];
            }
        }
        //计算最高柱子右侧的蓄水量
        $right_index = $len - 1;  //记录右边的最高挡水位置
        for($i=$len-2;$i>$max_index;$i--){
            if($height[$i + 1]>=$height[$right_index]){
                $right_index = $i + 1;
            }
            if($height[$i] < $height[$right_index]){
                $water += $height[$right_index] - $height[$i];
            }
        }
        return $water;
    }
}
```

