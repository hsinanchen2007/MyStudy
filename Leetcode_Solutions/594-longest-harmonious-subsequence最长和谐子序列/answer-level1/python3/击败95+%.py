### 解题思路
为什么采用hash表而不是直接使用list.count()计算？
答：因为list.count()超时了！
    不得不说hash表速度快，但是是以牺牲存储空间为代价的！

### 代码

```python3
class Solution:
    def findLHS(self, nums: List[int]) -> int:
        num_temp=set(nums)
        len_list=[]
        hash_map={}
        for num in nums:
            if num not in hash_map:
                hash_map[num]=1
            else:
                hash_map[num]+=1
        for num in num_temp:
            if num+1 in num_temp:
                len_list.append(hash_map[num]+hash_map[num+1])
        return max(len_list) if len_list else 0
```