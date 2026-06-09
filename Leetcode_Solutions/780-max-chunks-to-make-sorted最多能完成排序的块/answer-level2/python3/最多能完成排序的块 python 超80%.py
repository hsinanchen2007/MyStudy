> 思路:如果(i,j)能组成块，则数组i到j的元素是(i,i+1,...,j)的一个排列。所以依次统计累加和即可。
```python
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        
        cum = 0
        res = 0
        for i in range(len(arr)):
            cum += arr[i]
            #print(i,cum)
            if cum == i*(i+1)/2:
                res += 1
                #print('yes')
        return res
```