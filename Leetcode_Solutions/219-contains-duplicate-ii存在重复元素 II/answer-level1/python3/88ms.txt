```
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        str1 = nums[0:k]
        n1 = len(nums)
        if len(set(nums)) != n1:
            if k+1 >= n1:
                return(True)
        else:
            return(False)
        n2 = len(set(str1))
        if n2 < k:
            return(True)
        else:
            for i in range(k,n1):
                if nums[i] not in str1:
                    str1.append(nums[i])
                    str1.pop(0)
                else:
                    return(True)
            return(False)
```
