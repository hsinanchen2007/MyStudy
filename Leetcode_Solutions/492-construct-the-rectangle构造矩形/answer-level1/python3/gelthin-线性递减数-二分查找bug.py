### 解题思路
先找到平方根取整值，然后从平方根左右开始遍历，找到的第一个能够整除的数，就是解。
但这个方法效率实在太低。

#### 关于加速的思考：
考虑了对 area 求因子分解，然后再来计算，但首先因子分解不好做，其次有了因子分解也没有特别好的方法计算。
还有，对一些特例，因子分解没有用处。比如说，area = p1 * p2, p1 是一个中等大小的素数，p2 是一个超大的素数。 然后要每次递减1到达 p1, 极慢。

#### 关于二分搜索：
###### 从左边搜和从右边搜是不一样的，有微妙的区别，这个经常犯错，弄混。需要在好好看看liweiwei 大佬的解释。

``` python3
while i<j:
    mid = i + (j-i)//2
    if mid*mid < area:   # 找一个最小的 k， s.t. k*k >= area  # 这里我理解错了导致 bug
        i = mid + 1
    else:
        j = mid
```

``` python3
while i<j:
    mid = i + (j-i)//2
    if mid*mid > area:   # 找一个最大的 k， s.t. k*k <= area   这才是 sqrt 下取整
        j = mid - 1
    else:
        i = mid
```
由于此，提交出现了一次 bug。




### 代码

```python3
class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        #先求出 area 的平方根，再从平方根处开始遍历
        i, j = 0, area//2+1
        while i<j:
            mid = i + (j-i)//2
            if mid*mid < area:   # 找一个最小的 k， s.t. k*k >= area  # 这里我理解错了导致 bug
                i = mid + 1
            else:
                j = mid
        # W = i # bug 对 2 过不了，返回 W=2
        L = i
        while area % L!=0:
            L += 1
        return [L, area//L]
```