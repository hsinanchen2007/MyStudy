```
class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        self.count = 0 
        def merge(a,b):
            tmp = []
            i,j=0,0
            while i< len(a) and j < len(b):
                if a[i] > b[j]: self.count += len(b) - j;  tmp.append(a[i]); i+=1
                else: tmp.append(b[j]) ; j+=1
            while i< len(a): tmp.append(a[i]); i+=1
            while j< len(b): tmp.append(b[j]); j+=1
            return tmp
        
        def sort(start, end):
            if start >= end: return
            mid = (start + end) // 2
            sort(start, mid)
            sort(mid+1, end)
            nums[start: end+1] = merge(nums[start:mid+1],nums[mid+1: end+1])

        sort(0, len(nums)-1)
        return self.count
```
