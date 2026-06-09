### 解题思路
二分查找有两种求中值方法：
* med = (left + right) // 2
* med = left + (right - left) // 2
应该使用第二种，因为第一种会out of range

对于开方根求法：
* sqrt = x // sqrt
* 对比medium与x//medium来判断中值medium在开方根左侧还是右侧。
* 左侧：更新left至med + 1；右侧：更新right至med - 1
* 因退出循环时，right = left-1，即right<left。而对于2.83323,我们取2而非3，即取小的。所以输出right


### 代码

```python3
class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x
        l = 0
        r = x
        while l <= r:
            med = l + ( r - l ) // 2
            sqrt = x // med
            if med < sqrt:
                l = med +1
            elif med > sqrt:
                r = med -1
            else:
                return sqrt
        return r
```