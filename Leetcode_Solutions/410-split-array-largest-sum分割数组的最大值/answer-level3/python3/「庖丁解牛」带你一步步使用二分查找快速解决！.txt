## 二分查找的通常思路
+ 如果做多了二分查找的题，这道题应该会有思路。
+ 我们二分查找的时候，关键是要抓到**施以查找的变量**。即我们的`left`,`right` 和 `mid` 表示的是什么。
+ 对于简单题，往往就是列表的一项。比如对一个排序好的列表找到一个相应的值的位置，那么我们要施以查找的变量就是列表的下标，而缩小范围的依据就是`列表的值`。
+ 对于复杂的题，往往这个**施以查找的变量**会比较难抓。它往往不是列表里的一个项，而是一个要输出的值或判断依据做相应的变换。
+ 难点就在于划分出哪些是**施以查找的变量**，哪些是这些变量的**更新准则**。

## 针对这题的二分查找思路
+ 那么，对于这题，**施以查找的变量**是什么呢？
+ 我们注意到题目里说的`m个子数组各自和的最大值最小`。
+ 这是一个判断依据，也可以作为我们的**施以查找的变量**。
+ 显然，如果对这个数组，每个数单独成一数组，那么子数组的各自和的最大值，就是所有数中的最大值。
+ 而如果对这个数组不分组，那么子数组的各自和的最大值就是这个数组的和。
+ 这两个值对应的就是 `left` 和 `right`，即全分组与不分组的结果。
+ 套有我认为非常不错的这套「[二分查找模板](https://www.liwei.party/2019/06/19/leetcode-solution-new/search-insert-position/)」，可以很容易写出这样的代码。

```python
left, right = max(nums),sum(nums)
while left < right:
    mid = (left + right) // 2
    if #排除右侧的条件:
        right = mid
    else:
        left = mid + 1
return left
```
+ 它实际上无非是 模板 + 左右初值 而已。很简单吧？

## 更新依据
+ 刚刚的注释里写道 `排除右侧的条件`
+ 怎样排除左侧的条件呢？即，给定一个左，右，和中间值，如何判断我们需要的最大值在中间和左边围起来的范围内呢？
+ 我们假设给定了`mid`，那么需要判断，如果以`mid`作为最大值，能形成几组，然后和给定的`m`值作对比。显然，如果这个`mid`越大，要分出来的组数越少。
+ 如果形成的组数比要求的多，说明这个给定的`mid`太小了，要扩大，而如果形成的组数太少了，说明给定的`mid`太大了，要缩小。
+ 而如果相等呢？我们假设有这么一个题目，给定列表`[5,123]`和`m = 2`来找出最大值，假如在二分中选择了`124`，这样子只能分成两个组，而显然`124`这个数不是正确答案，正确答案是`123`，所以相等的时候，我们认为这个查找值`mid`应该缩小。
+ 如果设定一个`cnt`变量记录分组数，即可写成这样的形式。

```python
left, right = max(nums),sum(nums)
while left < right:
    mid = (left + right) // 2
    if cnt <= m:
        right = mid
    else:
        left = mid + 1
return left
```

## 计算cnt的方法
+ 可是分组数怎么计算呢？
+ 思路是这样，我们维护一个`cnt`和一个`sums`，表示目前的组数和目前的和。
+ 初始，自然`cnt = 1`，`sums = 0`
+ 我们遍历这个数组
    + 让`sums`加上这个遍历着的数
    + 如果这个加起来的和比上限要小，那么就遍历下一个
    + 如果这个加起来的和比上限大，说明要分组了
    + 那么`cnt += 1`，同时这个数作为新组的开头，即`sums = 这个遍历的数`
+ 这样可以写出一个函数
```python
def group(mid):
    sums, cnt = 0, 1
    for i in nums:
        if sums + i > mid:
            cnt += 1
            sums = i
        else:
            sums += i
    return cnt
```
+ 那么把这两块放在一起即
```python
class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        def group(mid):
            sums, cnt = 0, 1
            for i in nums:
                if sums + i > mid:
                    cnt += 1
                    sums = i
                else:
                    sums += i
            return cnt

        left, right = max(nums),sum(nums)
        while left < right:
            mid = (left + right) // 2
            sums, cnt = 0, 1
            for i in nums:
                if sums + i > mid:
                    cnt += 1
                    sums = i
                else:
                    sums += i
            if group(mid) <= m:
                right = mid
            else:
                left = mid + 1
        return left
```

## 完整代码

+ 如果不想再分函数，可以这么写
```python
class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        left, right = max(nums),sum(nums)
        while left < right:
            mid = (left + right) // 2
            sums, cnt = 0, 1
            for i in nums:
                if sums + i > mid:
                    cnt += 1
                    sums = i
                else:
                    sums += i
            if cnt <= m:
                right = mid
            else:
                left = mid + 1
        return left
```

## 总结
+ 相信解决完这道题，所有的「二分查找」对您来说都不是难题了。
+ 这里再回顾一下几个要点和重点。

1. 记住这份「[二分查找模板](https://www.liwei.party/2019/06/19/leetcode-solution-new/search-insert-position/)」，这样就无需继续处理很多细节问题了。其实背模板并不困难，无非就是几个要不要加等号，最后要不要判断，返回的是什么之类的。背这套是最方便好用的，而且也容易理解。
2. 找到**施以查找的变量**，很多比较难的题这个比较难抓，它往往不是列表里的一个项，而是一个要输出的值或判断依据做相应的变换。比如这题，就是以输出的值作为查找的变量。
3. 写出更新依据，即排除左分位（右分位）的依据可以单独列出一个函数。
4. 细节是魔鬼！