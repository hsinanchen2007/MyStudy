本题本质上是滑动窗口题，在一个k宽的窗口内，找两个数，它们之间差的绝对值，最大为t.

# （1）窗口记录下标
所以首先想到的是维护一个长度为k的窗口，用来记录下标，然后逐次比较差的绝对值
```
class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        window = set()
        for i, n in enumerate(nums):
            for j in window:
                if abs(nums[j] - n) <= t:
                    return True

            window.add(i)
            if len(window) > k:
                window.remove(i - k)

        return False
```
该方法的空间复杂度是O(min(n,k))，时间是O(n*k)，在k较大时会gg。这里也可以用常规滑动窗口中的deque，不过同样改变不了gg的命运。

# （2）窗口记录值
换一个角度，窗口直接记录值，而不是下标值。

```
class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        window = set()
        for i, n in enumerate(nums):
            for j in xrange(-t, t + 1):
                if j + n in window:
                    return True

            window.add(n)
            if len(window) > k:
                window.remove(nums[i - k])

        return False
```
这里在窗口记录值的依据是，如果值重复，必然导致return True，能活下来的必然是k个不重复的值，所以不用考虑覆盖的问题。
该方法的空间复杂度是O(min(n,k))，时间是O(n*t)，在t较大时会gg。

# （3）结合（1）（2）
既然t大了或者k大了都会gg，那就选择小的那个来判断。
```
class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        :type nums: List[int]
        :type k: int
        :type t: int
        :rtype: bool
        """
        window = set()
        for i, n in enumerate(nums):
            if 2 * t > k:
                for j in window:
                    if abs(j - n) <= t:
                        return True
            else:
                for j in xrange(-t, t + 1):
                    if j + n in window:
                        return True

            window.add(n)
            if len(window) > k:
                window.remove(nums[i - k])

        return False
```
该方法的空间复杂度是O(min(n,k))，时间是O(n*min(t,k)), 已经可以战胜90%的时间，虽然貌似没有这样的测试用例，但是当t，k同时很大的时候，这种方法仍然有问题。

# （4）引入桶
a和b的差的绝对值小于等于t，可以推导出abs(a/t - b/t) <= 1。那么我们可以把问题转换成：
*在一个k宽的窗口内，找两个数，它们之间除t之后的商的最大差值是1*

```
class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        div_nums = nums if t == 0 else [n / t for n in nums]
        window = {}
        for i, n in enumerate(div_nums):
            if t == 0:
                if n in window:
                    return True
            else:
                # 除完之后，相当于t = 1
                for j in range(-1, 2):
                    if j + n in window and abs(nums[i] - nums[window[j + n]]) <= t:
                        return True

            window[n] = i
            if len(window) > k:
                del window[div_nums[i - k]]

        return False
```
该方法的空间复杂度是O(min(n,k))，时间是O(n)。不论t, k如何变化，每个元素的操作都是常数时间。
但是，a和b的差的绝对值小于等于t，可以推导出abs(a/t - b/t) <= 1，反之不成立。也就说，这是一个充分不必要条件。
所以，找到abs(a/t - b/t) <= 1 之后，还不要doublecheck一下，实际的数值是否符合要求。
所以这里的window是个map，且多了一个检查：abs(nums[i] - nums[window[j + n]]) <= t

至此时间超过100%
