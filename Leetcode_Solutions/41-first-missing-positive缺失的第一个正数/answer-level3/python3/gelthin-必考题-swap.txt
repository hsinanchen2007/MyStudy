### 解题思路
这一题非常难。
字节跳动公司专用题。hangcen 被问到过。
下面两种解法可以直接用在习题 [448. 找到所有数组中消失的数字](https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/)

liweiwei 的解法也可以用在 [442. 数组中重复的数据](https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/)


#### 官方题解的方法，从 hash map 出发，由于只需要判断 1<= x <= n, 那么 x-1 就是有效的下标。
+ 用 nums[i] 的 +- 号来表示 i+1 元素是否出现过， 自己做自己的 bitmap, hash 表，非常巧妙。

#### [liweiwei 大神的解法非常好](https://leetcode-cn.com/problems/first-missing-positive/solution/tong-pai-xu-python-dai-ma-by-liweiwei1419/)，但是代码难写，要注意。可以看视频。
+ 如果 1<= nums[i]<=n, 就把 x= nums[i] 交换到 nums[nums[i]-1] 的位置上去。 这一想法在其他题目中也用到过。
+ 但是代码难写，交换之后的数也要注意处理，因此内部需要用一个 while 循环
+ nums[i] != nums[nums[i]-1] 可以避免重复数字带来的 BUG.
+ 可以不用双重 while， 只利用外面的一重 while 也是可以的，只需要控制变量不要加 1 [见代码](https://leetcode-cn.com/problems/first-missing-positive/solution/que-shi-de-di-yi-ge-zheng-shu-by-leetcode/289902)

#### python3 语法特性 swap
```
nums[i], nums[nums[i]-1] = nums[nums[i]-1], nums[i] ## BUG, 这么写代码会导致 bug
```
导致 bug, 陷入死循环。

之前有人说，x, y = y, x， 最右边的 y,x 是固定死的，不动。
但这里由于 nums[i] 发生了改变，可能会出现问题。



### 代码

```python3
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        i = 0
        while i<n:
            while 1<=nums[i]<=n and nums[i] != nums[nums[i]-1]:  ##while 循环,这里可以避免重复数字带来的 bug
                # nums[i], nums[nums[i]-1] = nums[nums[i]-1], nums[i] ## BUG, 这么写代码会导致 bug
                tmp = nums[i]
                nums[i] = nums[tmp-1]
                nums[tmp-1] = tmp 
            i += 1
        for i in range(n):
            if nums[i] != i+1:
                return i+1
        return n+1
```

``` python3
    j, n = 0, len(nums)
    while j < n:
        i = nums[j]
        if i > 0 and i <= n and j + 1 != i and nums[i - 1] != i:
            nums[i - 1], nums[j] = nums[j], nums[i - 1]
            continue  ## 这里只需要跳过 j += 1 的步骤，不需要使用双重 while, 直接利用外面的 while
        j += 1
```

#### 带BUG 的代码
``` pyhton3 
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i, x in enumerate(nums):
            if 1<=x<=n:
                if i+1 != x:
                    nums[x-1], nums[i] = x, nums[x-1]
                    if nums[i] != i+1:  
                        ## 这一段代码有 bug, 需要 1<=nums[i]<=n 才处理，并且需要循环处理，可能要一直循环下去
                        nums[x-1], nums[i] = x, nums[x-1]
        for i, x in enumerate(nums):
            if x != i+1:
                return i+1
        else:
            return n+1
```