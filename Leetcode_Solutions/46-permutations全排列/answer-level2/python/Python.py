### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def permute(self, nums):
        ans=[]
        length=len(nums)
        def help(temp,nums):
            if len(temp)==length:
                ans.append(temp)
                return
            for i in nums:
                if i not in temp:

                    help(temp+[i],nums)
            return
        help([],nums)

        return ans

```