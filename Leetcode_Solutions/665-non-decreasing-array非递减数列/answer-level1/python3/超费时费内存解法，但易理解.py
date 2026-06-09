### 解题思路
遍历数组，当遇到一个数比前一个数小的时候，只有两种替换方法，即：

将前一个数替换为这个数
将这个数替换为前一个数
替换完后，我们已经用完一次替换机会，分别检验两个替换后的数组，只要有一种符合非递减数列即可


作者：fssongwei
链接：https://leetcode-cn.com/problems/non-decreasing-array/solution/java-10000-by-fssongwei/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

### 代码

```python
class Solution(object):
    def checkPossibility(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        # 判断是否满足非递减数列
        def checkList(nums):
            i=1
            while i<len(nums):
                if nums[i]<nums[i-1]:
                    return False
                i += 1
            return True
        i = 1
        while i<len(nums):
            if nums[i]<nums[i-1]:
                case1=nums[:]
                case1[i]=case1[i-1]
                case2=nums[:]
                case2[i-1]=case2[i]
                return checkList(case1) or checkList(case2)
            else:
                i += 1
        return True
```