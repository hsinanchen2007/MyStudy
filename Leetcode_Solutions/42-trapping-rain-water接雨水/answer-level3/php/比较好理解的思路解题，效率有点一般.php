### 解题思路
初始化设置rain数组表示每个柱子能放的水的数量，之后一个个柱子遍历，如果下一个柱子比上一个柱子高，就倒退遍历到之前最高的柱子那边，取当前的柱子和最高的柱子的最小值，重新计算在这区间内的rain的值。最后把所有的rain相加就是结果了。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $height
     * @return Integer
     */
    function trap($height) {
        $rain = [];

        $max_index = 0;
        $max = $height[0];
        $count = count($height);
        for($i = 1; $i < $count; $i++ ) {
            if ($height[$i] < $height[$i-1])
                continue;
            for($j = $i -1; $j > $max_index; $j --) {
                if ($height[$i] > $height[$j])
                    $rain[$j] =  ($height[$i] >= $max ? $max : $height[$i]) - $height[$j];
                else
                    $j = 0;
            }
            if ($height[$i] >= $max) {
                $max = $height[$i];
                $max_index = $i;
            }
        }
        $sum = 0;
        foreach($rain as $val)
            $sum += $val;
        return $sum;
    }
}
```