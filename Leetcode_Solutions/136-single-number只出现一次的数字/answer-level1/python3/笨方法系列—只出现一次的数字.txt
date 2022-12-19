### 解题思路
还是笨方法，其实题目中隐含了一个信息，就是数组长度不可能是2，因为说了除了某一个元素A外，其他元素均出现了两次，本来我以为不可能是1的，但是测试用例里面有1，那我还是将len（nums）小于3加上去，通过纯条件判断，掐头去尾，先判断中间部分有没有找到唯一的那个元素，如果找到，就返回，如果找不到，就在头尾找，头找到了，就返回头部的，尾巴找到了，就返回尾巴的。该笨方法的时间复杂度是O(n),空间复杂度是O(1)。还有官方答案是异或实现的，这个我还要在好好领悟一下

补充一下，为什么我一开始会想到排序呢，就是刚好学习到希尔排序，觉得排序可以减少复杂度，就用了

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        nums.sort()
        b = 0
        if len(nums) < 3:
            return nums[0]
        else:
            for i in range (1,len(nums)-1):
                if nums[i] != nums[i+1] and nums[i] != nums[i-1]:
                    b = nums[i]
            if b == 0:
                if nums[0] != nums[1]:
                    b = nums[0]
                elif nums[len(nums)-1] != nums[len(nums)-2]:
                    b = nums[len(nums)-1]
        
            return b
```