### 解题思路
a, b, c为三角形三条边，a <= b <= c, 构成三角形条件a + b > c。

### 算法
- 升序排列
- 因为要找最大的周长，所以从后往前找。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $A
     * @return Integer
     */
    function largestPerimeter($A) {
        sort($A);
        for ($i = count($A) - 3; $i >= 0; $i--) {
            if ($A[$i] + $A[$i + 1] > $A[$i + 2]) return $A[$i] + $A[$i + 1] + $A[$i + 2];
        }

        return 0;
    }
}
```

### 算法复杂度
- 时间复杂度：快排的时间复杂度 O(nlog(n))
- 空间复杂度：局部遍历$i的存储。O(1)