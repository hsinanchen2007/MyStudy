### 解题思路
很迷的是，leetcode这里竟然不通过，就算是截取了依然不通过。
![leetcode.png](https://pic.leetcode-cn.com/97f6a4bd2ab19552bf99a0f55a0200d01fff722cd5205004c57009f793b353f1-leetcode.png)

### 代码

```python3
class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        #正确但无法提交
        #想象为leetcode378,m×n有序矩阵
        def search(target, m, n):
            i, j = 0, n-1
            count = 0
            while i < m and j >= 0:
                if nums1[i] + nums2[j] <= target:
                    count += j + 1
                    i += 1
                else:
                    j -= 1
            return count

        m, n = len(nums1), len(nums2)
        if not m or not n:
            return []
        low, high = nums1[0]+nums2[0], nums1[-1]+nums2[-1]
        while low < high:
            mid = low + (high-low)//2
            count = search(mid, m, n)
            if count < k:
                low = mid + 1
            else:
                high = mid
        #low为值的界限

        res = []
        i, j = 0, n-1
        while i < m and j >= 0:
            if nums1[i] + nums2[j] <= low:
                for col in range(j+1):
                    res.append([nums1[i], nums2[col]])
                i += 1
            else:
                j -= 1
        return res[:k]

        #堆
        # def push(i, j):
        #     if i < len(nums1) and j < len(nums2):
        #         heapq.heappush(heap, [nums1[i]+nums2[j], i, j])
    
        # heap = []
        # res = []
        # push(0, 0)
        # while heap and len(res) < k:
        #     cursum, i, j = heapq.heappop(heap)
        #     res.append([nums1[i], nums2[j]])
        #     push(i, j+1)
        #     if j == 0:
        #         push(i+1, 0)
        # return res

```