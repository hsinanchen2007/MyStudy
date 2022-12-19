一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 求关注求交流。

### 解题思路
思路1.暴力法
需要遍历所有数，o(n^2)复杂度，超时。

思路2.暴力+存储
也需要遍历所有数，只是反证丑数时节约时间，o(n^2)复杂度，依旧超时。

思路3.存储最小丑数，依次向上取，o(n)复杂度。


### 代码

```python
class Solution(object):
    def nthUglyNumber(self, index):
        """
        :type n: int
        :rtype: int
        """
        if index <= 1: return index
        res = [1] * index
        i2, i3, i5 = 0, 0, 0
        for i in range(1, index):
            res[i] = min(res[i2]*2, min(res[i3]*3, res[i5]*5))
            if res[i] == res[i2]*2: i2 += 1
            if res[i] == res[i3]*3: i3 += 1
            if res[i] == res[i5]*5: i5 += 1
        return res[-1]
```