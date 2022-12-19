### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def partitionLabels(self, nums):
        len_nums=len(nums)
        last={c:i for i,c in enumerate(nums)}
        print(last)
        j=anchor=0
        ans=[]
        for i,c in enumerate(nums):
            j=max(j,last[c])
            if j==i:
                ans.append(i-anchor+1)
                anchor=i+1
        return ans
```