```
class Solution:
    def smallestDifference(self, a: List[int], b: List[int]) -> int:

        # 排序后，相邻两数之间的距离最小
        if len(a) < len(b):
            return self.smallestDifference(b, a)
        a.sort()
        b.sort()
        left, right = 0, 0
        maxv = float('inf')
        while(left < len(a) and right < len(b)):
            if  a[left] < b[right]:
                maxv = min(maxv, abs(a[left] - b[right]))
                left += 1
            else:
                maxv = min(maxv, abs(a[left] - b[right]))
                right += 1     
        return maxv
            
                

```
