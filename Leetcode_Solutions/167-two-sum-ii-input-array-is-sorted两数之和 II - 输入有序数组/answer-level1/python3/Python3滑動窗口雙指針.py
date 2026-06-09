### 解题思路
首尾放置指針,若和>目標,右指針左移,
                            若和<目標 ,左指針右移
知道找到兩個指針的位置
### 代码

```python3
class Solution:
    def twoSum(self, n: List[int], tar: int) -> List[int]:
        l,r = 0,len(n)-1
        while l < r:
            if n[l] + n[r]  > tar:
                r -=1
            elif n[l]+n[r] < tar:
                l +=1
            else:
                return l+1,r+1
            
```