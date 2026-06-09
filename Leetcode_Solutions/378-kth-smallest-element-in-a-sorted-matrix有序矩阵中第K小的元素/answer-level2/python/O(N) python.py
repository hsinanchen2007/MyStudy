# 二分查找

1. 最小值low在左上角，最大值high在右下角，那么要找的元素区间在[low,high]。
mid=(low+high)/2，如果小于等于mid的数量小于k，则可以pass掉小于等于mid的值，即要找的元素一定大于mid，则low=mid+1。
这样每次折半，时间复杂度是log(high-low)，由于32位的int值，其最大log为32(因为除以2相当于右移1位)
2. 矩阵里查找小于某个值的数量，时间复杂度最小可以是O(N+N), 即O(N)
3. 所以总体时间复杂度是log(high-low)*O(N)，32算常数，即O(N)。

其他想法：如果一个matrix是[[1,2][3,2100000000]],k是2，那么其实遍历整个矩阵也只需要4次，但是二分查找却需要32*4次。

```
class Solution(object):

    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        
        # 求count是，从右上角往左下角遍历，O(N)
        def count(target, l):
            i = 0
            j = l-1
            counter = 0
            while j>= 0 and i< l:
                if matrix[i][j] <= target:  #!!! 小于等于，必须包含相等，即便等于目标值的数量
                    counter += j+1
                    i += 1
                else:
                    j -= 1
            return counter
        
        low = matrix[0][0]
        n = len(matrix)
        high = matrix[n-1][n-1]
        while low < high:
            mid = low + (high-low) >> 1
            c = count(mid, n)    # O(N)
            print low, high, mid, c
            if c < k:    # 包含相等的数量小于k，才将中间值加1
                low = mid+1
            else:
                high = mid
        return high
```

# 使用堆
思路：行跟列都是有序的，即问题可转换为在N个有序列表找第K小的元素。
1. 联想到这N个有序列表如果排好序，找到第K个就可以。如果2个有序列表，找到第K个，只需2个指针分别遍历2个列表，然后比较大小，找到第k个。
本题是N个有序列表，假如有N个指针指向每一行，每次取最小，然后将那一行的指针往后便宜，找到第K个。但是每次N个取最小，时间复杂度需要O(N)，有没有更小的复杂度？
堆或优先队列不就是解决这种问题的方案嘛。维护一个N大小的最小堆，这样每次pop最小的，只需要logN。
2. 当k<N时，只需遍历前k行，只需维护k大小的堆。
3. 时间复杂度：有序列表建堆是O(min(k,N)) + k*O(log(min(k,N)))，空间复杂度：O(min(k,N))
```
from heapq import *

class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        minheap = []
        n = len(matrix)
        for i in range(min(k, n)):  # 当k小于n时，只需遍历前k行
            heappush(minheap, (matrix[i][0], i, 0))  # 堆里的每个元素是（matrix[i][j], i, j）
            
        counter = 0
        x, i, j = 0, 0, 0
        while counter < k:
            counter += 1
            x, i, j = heappop(minheap)
            if j < n-1:
                heappush(minheap, (matrix[i][j+1], i, j+1))  # 向堆里加入该元素所在行的下一个元素
        return x
```
