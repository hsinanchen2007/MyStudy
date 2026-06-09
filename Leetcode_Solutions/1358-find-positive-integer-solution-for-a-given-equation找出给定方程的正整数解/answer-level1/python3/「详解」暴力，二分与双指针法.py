## 暴力法
### 思路
+ 遍历 x 从 1 到 z 的所有组合
    + 遍历 y 从 1 到 z 的所有组合
    + 如果两者作为变量使函数值等于目标值
    + 添加到答案中
+ 输出
+ 不推荐这个做法，完全没有利用到「递增」这个条件
### 代码
+ 一行搞定
```python
class Solution:
    def findSolution(self, customfunction: 'CustomFunction', z: int) -> List[List[int]]:
        return [[x,y]for x in range(1,z+1) for y in range(1,z+1) if customfunction.f(x,y) == z]
```
### 复杂度分析
+ 时间复杂度 $O(Z^2)$
+ 空间复杂度，不算记录答案的空间是 $O(1)$

## 二分查找法
### 思路
+ 先遍历 x
    + 对于每个 x ，可能存在一个对应的 y
    + 而 y 以及 f(x,y) 的值随着 y 的增加是增加的
    + 因此可以使用二分查找
+ 不推荐使用这个做法，因为只利用到了函数 f 对 y 变量是递增的，没有利用到对 x 也是这样。
### 代码
```python
class Solution:
    def findSolution(self, customfunction: 'CustomFunction', z: int) -> List[List[int]]:
        ans = []
        for x in range(1,z+1):
            left, right = 1, z
            while left < right:
                mid = (left + right) // 2
                res = customfunction.f(x,mid)
                if res < z:
                    left = mid + 1
                else:
                    right = mid
            if customfunction.f(x,left) == z:
                ans.append([x,left])
        return ans

```
### 复杂度
+ 时间复杂度 $O(ZlogZ)$
+ 空间复杂度，不算记录答案的空间是 $O(1)$

## 双指针法
### 思路
+ 由于函数 f 对于两个变量的偏导都是正的，那么可以使用双指针法。
+ 我们思考，先固定 x ，从1 开始，那么可以让 y 从后往前找到匹配值
+ 如果匹配到了以后，那么对应于这个 x 已经没用了，x 可以增加
+ 同时增加后的 x 要匹配的 y 就一定比上一个 y 少。
+ 这就是双指针法的思路。
+ 具体来讲就是
+ 一个 x 指向头(1)，一个 y 指向尾(1000)
+ 判断 x 和 y 能否使得函数值等于 z
    + 当这个函数值小了，就增加 x
    + 当这个函数值大了，就减少 y
    + 相等的时候添加到答案，同时 x 和 y 一起更新。
+ 推荐使用这个方法，利用了函数 f 对两个变量的偏导都是正的这个条件。
### 代码
```python
class Solution:
    def findSolution(self, customfunction: 'CustomFunction', z: int) -> List[List[int]]:
        ans,x,y = [],1,1000
        while x <= z and y >= 1:
            res = customfunction.f(x,y)
            if res < z:
                x += 1
            elif res > z: 
                y -= 1
            if res == z:
                ans.append([x,y])
                x += 1
                y -= 1
        return ans
```
### 复杂度分析
+ 时间复杂度 $O(Z)$
+ 空间复杂度，不算记录答案的空间是 $O(1)$