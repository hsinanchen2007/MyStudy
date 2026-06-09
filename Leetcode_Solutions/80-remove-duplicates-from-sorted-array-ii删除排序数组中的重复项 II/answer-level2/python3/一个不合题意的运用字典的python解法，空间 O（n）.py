和题意不符合，思路提供参考
```

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        search = dict()
        for i in nums:
            search[i] = search.get(i,0)+1
        print(search)

        for key in search:
            print(key)
            if search[key] <= 2:
                continue
            else:
                nums[nums.index(key) : nums.index(key)+search[key] ] = [key] * 2
                print('nums',nums)
        return len(nums)

```
