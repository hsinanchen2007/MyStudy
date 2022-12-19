### 解题思路
1.判断数字是否存在字典中，存在则加一，不存在则入字典。
2.对字典进行遍历，判断字典出现次数为1的，输出它的key。
### 代码

```python
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count_dict = {}
        for item in nums:
            if item in count_dict:
                count_dict[item] += 1
            else:
                count_dict[item] = 1
        print(count_dict)
        for key,value in count_dict.items():
            if value==1:
                return key    
```