
1. 执行用时 :12 ms, 在所有 PHP 提交中击败了98.93%的用户
2. 内存消耗 :16.8 MB, 在所有 PHP 提交中击败了64.18%的用户

### 解题思路
1. 双循环遍历方案可解，但时间复杂度O(n*n)，case运行时间超时
![1581390869138.jpg](https://pic.leetcode-cn.com/64159ea80ef5ed55b63e516ca9da3694789fec163bc7e9db42b9d9f107a7b732-1581390869138.jpg)

1. 将股票价格数组看做一条波折线，此题主要定位最高点与最低点，来寻找最大差值（利润值）
2. 默认第一个数组元素为最小值 $minVal，遍历数组发现较低元素则赋值 $minVal，否则计算差值
3. 时间复杂度：O(n), n为数组长度

### 代码

```php
class Solution {

    /**
     * @param Integer[] $prices
     * @return Integer
     */
    function maxProfit($prices) {
        $minVal = $prices['0'];
        $maxProfit = 0;
        for($i=1; $i<count($prices); $i++){
            if($prices[$i] < $minVal){
                $minVal = $prices[$i];
            } elseif(($prices[$i] - $minVal) > $maxProfit){
                $maxProfit = $prices[$i] - $minVal;
            }
        }
        return $maxProfit;
    }
}
```