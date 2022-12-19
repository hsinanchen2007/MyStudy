## 解题思路

由题意可以很容易的联想到使用查找表解决此问题， 遍历数组 nums ， 如果元素不在查找表中， 则将元素放入查找表中， 如果在查找表中查找到相同的元素， 则找到重复的元素

## 注意事项
对于 C/C++ 可以使用,数组, unordered_map, unordered_set 作为查找表进行解题。
对于 Python 可以使用 dict 或 set 进行解体， 因为 Python 的 dict 和 set 都是使用 hash 表实现的所以查找操作都是 O(1) 的时间复杂度。
但是， 如果想使用 list 进行解题， 则不应该使用 in 操作符， 因为 Python list 使用顺序表实现， 所以其 in 的时间复杂度为 O(n)
题目中已经说明 “ 数组 nums 里的所有数字都在 0～n-1 的范围内 ” 所以可以初始化一个长度为 n -1 的数组，然后使用 list[index] 操作来进行记录和查找 
python 内置数据类型时间复杂度可以参照：
[TimeComplexity](https://wiki.python.org/moin/TimeComplexity)


### 使用 hash 表的数据结构 (dict, set) 解题
```
class Solution(object):
    def findRepeatNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        table = set()
        for i in xrange(len(nums)):
            if nums[i] in table: # 存在记录过的数值， 代表出现重复的元素，此处 in 操作平均时间复杂度 O(1)
                return nums[i]
            else: # 不存在则记录
                table.add(nums[i])
```

### 使用 list 数据结构进行解体
```
class Solution(object):
    def findRepeatNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        array = [0] * len(nums) # 将所有元素数量都初始化为 0
        for n in nums:
            if array[n] > 0: # 存在记录过的数值， 代表出现重复的元素， 时间复杂度 O(1)
                return n
            else: # 不存在则记录
                array[n] += 1
```


