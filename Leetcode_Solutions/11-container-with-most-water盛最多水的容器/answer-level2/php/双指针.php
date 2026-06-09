### 解题思路
详见： [https://leetcode-cn.com/problems/container-with-most-water/solution/sheng-zui-duo-shui-de-rong-qi-by-leetcode/]()

### 代码

```php
class Solution {

    /**
     * @param Integer[] $height
     * @return Integer
     */
    function maxArea($height) {
        $max_area = 0;
        $head = 0;
        $tail = count($height) - 1;
        while ($head < $tail) {
            //最大面积
            $max_area = max($max_area, ($tail - $head) * min($height[$head], $height[$tail]));
            //面积由短板和底边长决定，所以从最两边开始向中心推进，记录当前面积后，从两边更短的一边向里一格一格推进
            if ($height[$head] > $height[$tail]) {
                $tail--;
            } else {
                $head++;
            }
        }

        return $max_area;

    }
}
```