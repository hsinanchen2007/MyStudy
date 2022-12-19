思路:最大利益就是数组中的最大差值,所以用一个变量存储当前数组中最小值,并计算键值与最小值的差(利益),取最大差,遍历一遍数组就可以了.
代码如下:
```
class Solution {

    /**
     * @param Integer[] $prices
     * @return Integer
     */
    function maxProfit($prices) {
        $min = $prices[0];
        $profit = 0;
        foreach($prices as $k => $v){
            $min = $min > $v ? $v : $min;
            $profit = $v-$min > $profit ? $v-$min : $profit;
        }
        return $profit;
    }
}
```