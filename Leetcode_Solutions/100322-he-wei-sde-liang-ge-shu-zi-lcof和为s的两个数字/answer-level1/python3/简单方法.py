对于每一个新遇到的数num计算与他配对的数result，如果在集合里找到result，那么配对成功直接输出，如果集合里找不到这个数，就把num放入集合。往后再走一个数。

这个方法没有利用已给数组是递增排序的信息（任何打乱的数组都可以用上面的方法），所以速度并不快。但时间和空间复杂度都是O（n）。
```
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        myset=set()
        for num in nums:
            result = target-num
            if result not in myset:
                myset.add(num)
            else:
                return [num,result]
```
