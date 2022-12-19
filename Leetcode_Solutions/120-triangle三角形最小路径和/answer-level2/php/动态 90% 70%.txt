### 解题思路
动态自下至上

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $triangle
     * @return Integer
     */
    function minimumTotal($triangle) {
        //从倒数第二层开始，每一个内循环计算此层到下一层的最小路径之和
        for ($i = count($triangle) - 2; $i >=0; $i--) {
            for ($j = 0; $j < count($triangle[$i]); $j++) {
                $triangle[$i][$j] += min($triangle[$i + 1][$j], $triangle[$i + 1][$j + 1]);
            }
        }

        return $triangle[0][0];
    }
}
```