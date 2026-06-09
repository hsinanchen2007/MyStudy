# 方法1：遍历数组
简单遍历数组，将遍历过的放进一个set()里，每次遍历都用in方法判断是否在set()里，若存在，return该数字，否则将该数字加入set()里继续遍历
```
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int: 
        temp = set()
        for i in range(len(nums)):
            if nums[i] in temp:
                return nums[i]
            else:
                temp.add(nums[i])
```
**注意：** 此处不能用list()来存放已遍历的数字
**原因：** num in list()的时间复杂度为 **O(n)**，而num in set()的时间复杂度为 **O(1)**，若用list()，遇到长数组会超出时间限制

# 方法2：原地置换
题目中一个比较特殊的条件为：nums长n，用来存放0~n-1的数字。
因此，加入对nums进行排序，若无重复元素，nums[i]存放的数字即为i。所以可以对nums进行遍历，同时将数字i放到nums索引i的位置上，若该位置已有数字i，则数字i重复
```
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int: 
        for i in range(len(nums)):
            if nums[i] != i:
                if nums[nums[i]] == nums[i]:
                    return nums[i]
                nums[nums[i]], nums[i] = nums[i], nums[nums[i]]

```
**以上两种方法的执行用时和内存消耗相同，分别为56ms和22.8ms**

# 另外发现
若将方法1中的
```
for i in range(len(nums)):
```
改为
```
for num in nums:
```
会导致运行时间和内存消耗的上升。