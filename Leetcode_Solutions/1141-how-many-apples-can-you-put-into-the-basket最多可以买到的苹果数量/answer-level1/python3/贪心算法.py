```
class Solution:
    def maxNumberOfApples(self, arr: List[int]) -> int:
        if arr == []:
            return 0

        arr, bag_size, count = sorted(arr), 5000, 0
        for apple in arr:
            bag_size -= apple
            if bag_size <= 0:
                return count
            count += 1
        return count
```
