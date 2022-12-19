### 解题思路
哈希表

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        hashmap={}
        for num in nums:
            if(num in hashmap):
                hashmap[num]+=1
            else:
                hashmap[num]=1
        for i in hashmap:
            if(hashmap[i]>len(nums)//2):
                return i

        return -1
```