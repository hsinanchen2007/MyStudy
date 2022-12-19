一、算法思想
创建集合，然后依次遍历数组，如果数组中的数不在集合中，将其加入集合；如果已在集合中，说明其重复出现，将其作为结果返回。
二、算法实现
```
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        my_set = set()
        for num in nums:
            if num in my_set:
                return num
            else:
                my_set.add(num)
```
三、复杂度分析
1.时间复杂度：O(N)。集合中查找和往集合中添加元素都为常量时间复杂度操作，算法中用到了一层循环，故时间复杂度为O(N)。
2.空间复杂度：O(N)。创建的集合数据类型的空间复杂度为O(N)。