
```
def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        hash_set = {}
        for index,num in enumerate(nums):
            if num not in hash_set:
                hash_set[num] = index
            else:
                if index - hash_set[num] <= k:
                    return True
                else:
                    hash_set[num] = index 
        return False
```

