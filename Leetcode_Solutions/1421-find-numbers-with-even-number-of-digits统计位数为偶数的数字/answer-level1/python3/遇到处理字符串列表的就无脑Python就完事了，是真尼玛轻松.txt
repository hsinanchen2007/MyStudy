### 解题思路
执行用时 :
56 ms
, 在所有 python3 提交中击败了
86.61%
的用户
内存消耗 :
12.6 MB
, 在所有 python3 提交中击败了
100.00%
的用户
### 代码

```python3
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        res=0
        for each_int in nums:
            each_str=str(each_int)
            if len(each_str)%2==0:
                res+=1
        return res
```