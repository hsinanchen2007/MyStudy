### 解题思路
求最小K个和，就是求和的相反数的最大的K个，用小根堆存，来一个，只有小于这K个的最小值才替换。
[此题解](https://leetcode-cn.com/problems/find-k-pairs-with-smallest-sums/solution/python-da-gen-dui-by-frankchen250/)代码对，理解错

### 代码

```python
class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        heap = []
        for num1 in nums1:
            for num2 in nums2:
                if len(heap) < k:
                    heapq.heappush(heap, (-(num1 + num2) , [num1, num2]))
                else:
                    if num1 + num2 < -heap[0][0]:
                        #heapq.heappushpop(heap, (-(num1 + num2), [num1, num2])) #ok
                        heapq.heappop(heap) #分解动作
                        heapq.heappush(heap, (-(num1 + num2), [num1, num2]))
        return [item[1] for item in heap]


```