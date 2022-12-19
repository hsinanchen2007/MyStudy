### 解题思路
![image.png](https://pic.leetcode-cn.com/c921778b82025e74bf7a772ed5d88a9640d518a0f35b8195b40ab6caaae49d75-image.png)

- 根据题目的要求,两个数字`m`和`n`能拼接成数字`mn`和`nm`,如果`mn < nm`那么现在他们的相对位置是正确的,如果`mn > nm`,那么就需要将`n`移到`m`的前面,根据这样的特性我们能将整个数组进行排列,得到最终的结果.
- 我们在比较的时候先将数据转换成`str`格式的,利用`str`格式的字符串直接比较就可以
- 这个题目要求我们转换成字符串的形式,是隐含了一个大数的问题

### 代码

```python
class Solution(object):
    def minNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        if not nums:
            return None
        for i in range(len(nums)):
            nums[i] = str(nums[i])
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                if (nums[i] + nums[j]) > (nums[j] + nums[i]):
                    nums[i], nums[j] = nums[j], nums[i]
        
        return ''.join(nums)
                
    

```