### 解题思路
max用于记录最大连续的1的个数，count用于记录每一块1中1的个数。
一次循环，首先比较count是否大于max，更新max。
然后判断当前字符是否为1，是的话count加1。如果为0，则count清零（进循环的时候count已经和max进行比较了）
最后结束循环还要再次判断count和max大小，防止由于最后一个字符为1之后，count不为0但是还未和max进行比较

### 代码

```python3
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        max = 0
        count = 0
        for i in range(len(nums)):
            if count > max:
                max = count
            if nums[i]==1:
                count +=1
            if nums[i]==0:
                count = 0
        max = count if count>max else max
        return max
```