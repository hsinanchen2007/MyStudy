
```
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        def partition(data, left, right):
            pivot = data[left][1]
            j = left
            for i in range(j + 1, len(data)):
                if data[i][1] < pivot:
                    j += 1
                    data[i][:], data[j][:] = data[j][:], data[i][:]
                    # print(nums)
            data[left][:], data[j][:] = data[j][:], data[left][:]
            return j
        
        import collections
        lookup = collections.Counter(nums)
        data = []
        for key, val in lookup.items():
            data.append([key, val])
        size = len(data)
        target = size -k
        left, right = 0, size - 1
        idx = partition(data, left, right)
        while idx != target:
            if idx < target:
                left = idx + 1
            else:
                right = idx - 1
            idx = partition(data, left, right)
        # print(data, idx)
        res = []
        for i in range(idx, idx + k):
            res.append(data[i][0])
        return res
```
