### 解题思路
此处撰写解题思路

### 代码

```python
class L(str):
    def __lt__(x,y):
        return x + y > y + x #什么情况下x要排在y前面（小于等于函数嘛，规定了“小的在前面”）


class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        ans = ''.join(sorted(map(str,nums),key=L))
        return ans if ans[0]!='0' else '0'
        
```