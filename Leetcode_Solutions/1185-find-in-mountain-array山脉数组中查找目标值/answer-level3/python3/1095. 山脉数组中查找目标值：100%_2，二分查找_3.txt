困难里的基础题，只要用了分治，时间都差不多的。

解法一是把二分查找坐标做成函数了，二分查找中值判断条件用匿名函数传递。

解法二就是正常分开做的，解法一比较快，解法二比较容易理解,其实解法一也就是把解法二的条件泛化而已。

解法一：

![image.png](https://pic.leetcode-cn.com/da7c7c95cfb8d3def7fb6eba9b53a7bf255917761abc9bab0507535d474597cb-image.png)

```python []
class Solution:
    def findInMountainArray(self, target: int, arr: 'MountainArray') -> int:
        def f(l, r, gl, gr):
            while l <= r:
                m = (l + r) // 2
                if gl(m):
                    l = m + 1
                elif gr(m):
                    r = m - 1
                else:
                    return m
            return -1
        n = arr.length()
        h = f(1, n - 2, lambda m: arr.get(m) < arr.get(m + 1), lambda m: arr.get(m) < arr.get(m - 1))
        t = f(0, h, lambda m: arr.get(m) < target, lambda m: arr.get(m) > target)
        if t != -1:
            return t
        return f(h + 1, n - 1, lambda m: arr.get(m) > target, lambda m: arr.get(m) < target)
```

解法二：

![image.png](https://pic.leetcode-cn.com/d7d25f51d0d4074e66a672362f849089a2e585fee8b5a8acfe5cdfe4cb169e87-image.png)

```python []
class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:

        n = mountain_arr.length()
        
        l, r = 1, n - 2
        while l <= r:
            m = (l + r) // 2
            if mountain_arr.get(m) < mountain_arr.get(m + 1):       #区间中值比右边小就向右找山峰
                l = m + 1
            elif mountain_arr.get(m) < mountain_arr.get(m - 1):     #区间中值比左边小就向左找山峰
                r = m - 1
            else:
                h = m       #山顶坐标
                break
        
        l, r = 0, h
        while l <= r:
            m = (l + r) //2
            if mountain_arr.get(m) < target:
                l = m + 1
            elif mountain_arr.get(m) > target:
                r = m - 1
            else:
                return m
        
        l, r = h + 1, n - 1
        while l <= r:
            m = (l + r) //2
            if mountain_arr.get(m) > target:        #注意符号方向
                l = m + 1
            elif mountain_arr.get(m) < target:
                r = m - 1
            else:
                return m
        
        return -1
```
