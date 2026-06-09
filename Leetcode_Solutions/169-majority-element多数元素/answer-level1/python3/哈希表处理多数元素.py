### 解题思路
用哈希表搜索每个字符出现的次数，超过n/2时就停止检索直接返回该字符了。

ps:还是用了好多内存，伐开心

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        hashmap={}
        i=0
        str_len=len(nums)/2
        for num in nums:
            j = hashmap.get(nums[i])
            i+=1
            if j is None:
                hashmap[num] = 1
            if j is not None:
                hashmap[num] += 1
            if hashmap[num] > str_len:
                return num
                break
                #return hashmap[num]
