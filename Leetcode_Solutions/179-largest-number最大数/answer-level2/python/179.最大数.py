### 解题思路
- 根据规则打擂，对数字进行排序。
- 这里的规则是两个数有两种组合，我们希望保留组合大
- 确定位置i的值时，需要将位置i以后的每个数与位置i的数进行组合，将大数组合的前一个数放到位置i;知道比较完位置i以后的所有数字。

### 代码

```python
class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        
        L = len(nums)
        if nums.count(0)== L:return "0"
        
        s = list(map(str,nums))
        #按规则打擂排排站
        for target in range(L):
            for i in range(target+1,L):
                if int(s[target]+ s[i]) < int(s[i]+s[target]):
                    s[target],s[i] = s[i],s[target]
        res = ''.join(s)
        return res 
```