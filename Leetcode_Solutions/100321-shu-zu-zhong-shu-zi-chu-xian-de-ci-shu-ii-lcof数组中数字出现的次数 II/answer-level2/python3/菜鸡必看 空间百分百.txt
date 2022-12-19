### 解题思路
最后的t_hash中只有一个元素 这个for是假的哈哈

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        t_hash={}
        for num in nums :
            if num not in t_hash :
                t_hash[num]=1
            elif t_hash[num] ==2 :
                del t_hash[num]
            else :
                t_hash[num]+=1
        for key in t_hash :
            return key
```