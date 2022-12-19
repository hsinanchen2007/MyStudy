### 解题思路
这个就是灵活运用了hashmap,最核心的就是注释那两行，一定要注意

### 代码

```python3
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        hash_mp ={0:1}
        sums = 0
        count = 0
        for i in range(len(nums)):
            sums += nums[i]
            if sums-k  in hash_mp:
                count += hash_mp[sums-k] #这里是最容易错的，一个是count加上原来的个数，一个是找sums-k的数
            if  sums in hash_mp:
                hash_mp[sums] +=1
            else:
                hash_mp[sums]=1
        return count
```