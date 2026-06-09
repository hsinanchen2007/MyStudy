### 解题思路
所给数组长度为n，显然，缺失的第一个的正数的范围最小为1，最大为n+1，所以除去最后两个边界情况，所缺正数是所给数组的某一个索引，因此解题可以将索引与数字本身相联系。
假设数组中的n个元素范围最小是1，最大是n，那么遍历数组中的每个元素，将数组中以当前所遍历的这个元素为索引所指向的元素变为负数，那么变换之后的数组中第一个出现的正数所对应的索引就是要找的值，当然严格来说，此时所能找到的缺失正数的范围是1到n（为n的情况是索引1之后的元素全为负数），这个问题也好解决，就是把索引为0所指向的元素去代表n所指向的元素。
实际题中元素的范围多了小于等于0和大于n两个部分，因为数组变换之后的元素正负有意义，以及索引大于n时程序会出错，所以这两部分数可以换为1（不能换为0，因为变换之后的元素正负是有意义的，需要能去判断正负），当然这样需要事先检查1是否为缺失的正数。

### 代码

```python
class Solution:
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        
        # 基本情况
        if 1 not in nums:
            return 1
        
        # nums = [1]
        if n == 1:
            return 2
        

        for i in range(n):
            if nums[i] <= 0 or nums[i] > n:
                nums[i] = 1
        
        # 使用索引和数字符号作为检查器
        # 例如，如果 nums[1] 是负数表示在数组中出现了数字 `1`
        # 如果 nums[2] 是正数 表示数字 2 没有出现
        for i in range(n): 
            a = abs(nums[i])
            # 如果发现了一个数字 a - 改变第 a 个元素的符号
            # 注意重复元素只需操作一次
            if a == n:
                nums[0] = - abs(nums[0])
            else:
                nums[a] = - abs(nums[a])
            
        # 现在第一个正数的下标
        # 就是第一个缺失的数
        for i in range(1, n):
            if nums[i] > 0:
                return i
        
        if nums[0] > 0:
            return n
            
        return n + 1
```