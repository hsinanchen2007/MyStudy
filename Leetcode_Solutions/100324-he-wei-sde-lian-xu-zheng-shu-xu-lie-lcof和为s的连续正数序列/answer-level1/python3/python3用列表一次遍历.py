### 解题思路
其实就是类似滑动窗口一样

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target):
        # 最少两个，也就是说遍历到一半就不用继续下去了
        # 用列表，不过每次弹出的是0位置上的
        if target < 3:
            return [[target]]
        res = []
        tmp = []
        sum_tmp = 0
        for i in range(1, target//2 + 2):
            tmp.append(i)
            sum_tmp += i
            if sum_tmp == target:
                res.append(tmp[:])
            elif sum_tmp > target:
                while sum_tmp > target:
                    sum_tmp -= tmp[0]
                    tmp = tmp[1:]
                if sum_tmp == target:
                    # 在这不能直接放进去，要拷贝一下
                    res.append(tmp[:])
        return res
```