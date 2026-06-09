### 解题思路
此处撰写解题思路
暴力破解法
### 代码

```python3
class Solution:
    def twoSum(self, num, target):
        for i in range(0,len(num)-1):
            for j in range(i+1,len(num)):			
                if num[i] + num[j] == target:
                    return [i,j]
        return []
```