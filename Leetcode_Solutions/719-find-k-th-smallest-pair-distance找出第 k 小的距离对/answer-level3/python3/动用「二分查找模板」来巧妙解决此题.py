## 思路
+ 这道题意思要花功夫理解一下，这里的题解基本上就是官方题解第三解套用二分查找模板（其实原题解就很接近这套模板了）。
+ 为了减少时间复杂度，需要使用「二分查找」。
+ 但这题难就难在，我们要查找的东西，不是那两个具体的数，而是**根据两个数的差值**进行二分查找。
+ 我们首先需要对全体数排列
+ 接着呢，0想必是最小的差值（即没有差值），而第0和最后一个，想必是最大的那个。
+ 但是第K小的呢？怎么找呢？
+ 假如，我们取了 0 为左值，而第0和最后一个差的值作为右值，那么中间值就是要取的mid。
+ 我们去找一找，选好这个mid后，存不存在大于k个组合，他们的差小于mid
+ 如果存在的话，说明这个中值取得太大，反之就是太小，即一个经典的二分查找。
+ 这里用`liweiwei1419`大佬总结的「[二分查找模板](https://www.liwei.party/2019/06/19/leetcode-solution-new/search-insert-position/)」来快速解决细节问题。
+ 我们可以写出这样的代码。
```python
nums.sort()
left,right = 0,nums[-1] - nums[0]
while left < right:
    mid = (left + right) // 2
    if # 整个数列中比mid小的数列对的数量小于k个:
        left = mid + 1
    else:
        right = left

return left
```
+ 最后一步，把`整个数列中比mid小的数列对的数量小于k个`写出来，就好哩！
+ 这里直接搬官方题解的解释
+ 我们可以使用双指针来计算出所有小于等于`mid`的距离对数目。
+ 我们维护 left 和 right
+ 其中 right 通过循环逐渐递增
+ left 在每次循环中被维护，使得它满足 nums[right] - nums[left] <= mid 且最小。
+ 这样对于 nums[right]，以它为右端的满足距离小于等于 mid 的距离对数目即为 right - left。
+ 我们在循环中对这些 right - left 进行累加，就得到了所有小于等于 mid 的距离对数目。
+ 这里没有像官方题解一样分一个函数，其实原理都一样。

## 代码

```python
class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        nums.sort()
        left, right = 0,nums[-1] - nums[0]
        while left < right:
            mid = (left + right) // 2
            cnt, start = 0, 0
            for i in range(len(nums)):
                while nums[i] - nums[start] > mid:
                    start += 1
                cnt += i - start
            if cnt < k:
                left = mid + 1
            else:
                right = mid
        return left
```