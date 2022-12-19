### 解题思路
用字典（哈希表）记录列表每个元素及其出现次数
用zip函数匹配最大值--键
输出对应键即可

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        if len(nums)==1:
            return nums[0]
        Hashmap={}
        for i in nums:
            if i not in Hashmap:
                Hashmap[i]=1
            elif i in Hashmap:
                Hashmap[i]+=1
        max_Hash = max(zip(Hashmap.values(),Hashmap.keys()))
        if max_Hash[0]==1:
            return -1
        elif max_Hash[0]!=1:
            return max_Hash[1]
```