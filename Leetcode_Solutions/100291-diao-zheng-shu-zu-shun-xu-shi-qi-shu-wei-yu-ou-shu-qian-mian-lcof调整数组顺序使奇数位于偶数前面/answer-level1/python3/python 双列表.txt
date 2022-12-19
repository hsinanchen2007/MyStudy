### 解题思路
利用两个列表进行判断存：
     如果为奇数，存入res1
     如果为偶数，存入res2
     返回 res1+res2

### 代码

```python3
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        res1=[]
        res2=[]
        for i in nums:
            if i%2!=0:
                res1.append(i)
            else:
                res2.append(i)
        return res1+res2
            
```