### 解题思路
此处撰写解题思路
本题的解法其实就是求范围的交集，我一开始被自己的斜着的case卡住了。。本题更简单一些，正正方方的矩形。。
在实际工程中，也有很多适用的场景，比如求时间的交集范围等。
我们只需要将不相交的情况排除掉，然后取非，就是所有相交的情况了

### 代码

```php
class Solution {

    /**
     * @param Integer[] $rec1
     * @param Integer[] $rec2
     * @return Boolean
     */
    function isRectangleOverlap($rec1, $rec2) {
        return !($rec2[2] <= $rec1[0] ||
                $rec2[0] >= $rec1[2] ||
                $rec2[1] >= $rec1[3] ||
                $rec2[3] <= $rec1[1]
        );
    }
}
```