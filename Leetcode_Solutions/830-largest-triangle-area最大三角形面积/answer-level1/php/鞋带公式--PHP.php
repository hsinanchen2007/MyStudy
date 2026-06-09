### 解题思路
[鞋带公式](https://blog.csdn.net/c___c18/article/details/89284965))，用于计算任意多边形的面积，可用于计算三角形的面积；

[海伦公式](https://baike.baidu.com/item/%E6%B5%B7%E4%BC%A6%E5%85%AC%E5%BC%8F)，从三个顶点得到三边长，并使用海伦公司计算出面积；

三角形面积公式 S = 1/2 * a * b * sin(C)，首先得到两边的长度，通过叉积算出夹角的正弦值，并使用公式计算出面积。


原来计算三角形面积还有这么多种方式。

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $points
     * @return Float
     */
    function largestTriangleArea($points) {
        $len = count($points);
        $max_area = 0;
        for ($i = 0; $i < $len; $i++) {
            for ($j = $i + 1; $j < $len; $j++) {
                for ($k = $j + 1; $k < $len; $k++) {
                    $area = $this->getArea($points[$i], $points[$j], $points[$k]);
                    $max_area = max($max_area, $area);
                }
            }
        }

        return $max_area;
    }

    public function getArea($point1, $point2, $point3)
    {
        return abs(($point1[0] * $point2[1] + $point2[0] * $point3[1] + $point3[0] * $point1[1]) - ($point1[1] * $point2[0] + $point2[1] * $point3[0] + $point3[1] * $point1[0])) * 0.5;
    }
}
```

### 算法复杂度
- 时间复杂度： O(N * N * N)
- 空间复杂度：O(1)

### 参考
[leetcode](https://leetcode-cn.com/problems/largest-triangle-area/solution/zui-da-san-jiao-xing-mian-ji-by-leetcode/)