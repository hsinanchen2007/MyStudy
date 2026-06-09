### 解题思路

看起来很难，但是找到规律后实现很简单。

因为两个步骤是**交替进行**的。所以:

1. 当前数组中**最大的一个数**必然是当前的 x（代码中的 current_x）。
2. 数组所有数的和减去这个最大数，就是这次次的 x 比上一次 x 增大的增量（inc）。

经过 [@wangtaoking1](/u/wangtaoking1/) 提醒，修改了循环中更新 x 的方法。之前是 x = x - inc，现在是 x = x % inc。

又得到 zdyxry 的提醒，第二版代码里可能出现 inc == 0 的问题。如果 target 数组长度**大于 1**， inc 一定大于 0，因为 `inc = sum(target) - current_x`  ， traget 中每个元素都大于等于 1，所以 target 的元素和，减去 target 中最大的元素大于 0。
但是如果 target **长度为 1**。第二版代码的 inc == 0，改进后的代码出现除 0 错误; 而最初代码陷入死循环。

还是没考虑全，经 [@Gorilla](/u/gorilla/) 提醒，增加对 `current_x % inc` 为 0 的判断。(2020 年 3 月 16 日)

### 代码

第四版代码，增加对 `current_x % inc` 为 0 的判断。
```python
class Solution:
    def isPossible(self, target: List[int]) -> bool:
        if len(target) == 1: return target[0] == 1
        while True: 
            current_x = max(target)
            if current_x == 1:   
                return True # 最大的数等于 1 了而且数组中无小于 1 的数，那么说明整个数组都是 1，返回 True
            idx = target.index(current_x)
            inc = sum(target) - current_x 
            target[idx] = current_x % inc
            if inc >= current_x or target[idx] == 0: 
                return False # inc 大于等于 x，这样将会出现小于 1 的值，不是合法情况，返回 False
```


第三版代码（在第二版基础上排除了 target 长度为 1 的情况，避免 inc == 0）

```python
class Solution:
    def isPossible(self, target: List[int]) -> bool:
        if len(target) == 1: return target[0] == 1
        while True: 
            current_x = max(target)
            if current_x == 1:   
                return True # 最大的数等于 1 了而且数组中无小于 1 的数，那么说明整个数组都是 1，返回 True
            idx = target.index(current_x)
            inc = sum(target) - current_x
            if inc >= current_x: 
                return False # inc 大于等于 x，这样将会出现小于 1 的值，不是合法情况，返回 False
            target[idx] = current_x % inc
```

第二版代码（target 长度为 1，且这个元素不等于 1 时， inc 等于 0，发生除零错误）
```python
class Solution:
    def isPossible(self, target: List[int]) -> bool:
        while True: 
            current_x = max(target)
            if current_x == 1:   
                return True # 最大的数等于 1 了而且数组中无小于 1 的数，那么说明整个数组都是 1，返回 True
            idx = target.index(current_x)
            s = sum(target)
            inc = s - current_x
            if inc >= current_x: 
                return False # inc 大于等于 x，这样将会出现小于 1 的值，不是合法情况，返回 False
            target[idx] = current_x % inc
```

最初代码（有数据会超时，比如 [1, 1000000000]）

```python
class Solution:
    def isPossible(self, target: List[int]) -> bool:
        while True:
            cx = max(target)
            if cx == 1:
                return True
            idx = target.index(cx)
            s = sum(target)
            lv = cx - (s - cx)
            if lv < 1:
                return False
            target[idx] = lv
```



欢迎来我的博客： [https://codeplot.top/](https://codeplot.top/)
我的博客刷题分类：[https://codeplot.top/categories/%E5%88%B7%E9%A2%98/](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)

