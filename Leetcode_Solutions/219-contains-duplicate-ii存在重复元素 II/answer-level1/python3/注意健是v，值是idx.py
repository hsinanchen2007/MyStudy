### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:

        # if k == 0:
        #     return False

        n2id = {}
        for idx,v in enumerate(nums):
            if v in n2id and idx-n2id[v]<=k:
                return True
            else:
                n2id[v] = idx
        return False

```