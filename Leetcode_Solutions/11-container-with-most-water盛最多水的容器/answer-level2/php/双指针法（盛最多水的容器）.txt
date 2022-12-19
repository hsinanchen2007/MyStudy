# 基础版
// 很好的解题思路，学习了，但内存使用度过大，需优化

![9-image.png](https://pic.leetcode-cn.com/26309f7eb4397a758093c018c137ae56a64c1d3de4c7072ac83ca1e31b6f2fe8-9-image.png)

1. 在等高情况下，桶直径越大，装水越多
2. 所以在两端出现最大值的概率比较大，从两端经过比较取出所有可能出现的面积，放在一个数组中，最后取得最大值即可
3. 关于比较：
    1. 如果左侧板小于右侧板，则左侧板向左移动一位，将所有取得的面积值放在数组中
    2. 如果左侧板大于右侧板，则右侧板左移一位，将所有取得的面积值放在数组中
    3. 如果相等，随便那块都行
    
![1562390521(1).jpg](https://pic.leetcode-cn.com/3f8dfec01e33b88863d06501276eb699503febae89a9459638e97cc30ef3497c-1562390521\(1\).jpg)


```
    function maxArea($height) {
        $r = count($height)-1;
        $l = 0;
        $areas = [];
        for ($i = $r; $i > 0; --$i) {
            $area = min($height[$l], $height[$r]) * $i;
            $areas[] = $area;
            if ($height[$r] > $height[$l]) {
                ++$l;
            } else {
                --$r;
            }
        }
        return max($areas);
    }
```
