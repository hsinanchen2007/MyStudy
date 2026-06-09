### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        mp = []
        for i, num in enumerate(nums):
            mp.append([num,i])
        mp.sort()
        for i, m in enumerate(mp):
            if i>0:
                if mp[i][0]==mp[i-1][0] and abs(mp[i][1]-mp[i-1][1])<=k:
                    return True
        return False
```