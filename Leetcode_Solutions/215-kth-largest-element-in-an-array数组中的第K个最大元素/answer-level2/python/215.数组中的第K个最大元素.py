### 解题思路
方法1：sort排序，输出n-k位
```
class Solution(object):
    def findKthLargest(self, nums, k):
        nums.sort()
        return nums[len(nums)-k]
```
方法2：利用nlargest，输出倒数第k位
```
class Solution(object):
    def findKthLargest(self, nums, k):
        from heapq import nlargest
        return nlargest(k,nums)[-1]
```
方法3：利用最大堆heap,heap是从小到大排列前k个最大，输出k[0]即可。
heappush（heap,a）,把a放在heap中
heaprepalce(heap,b),把b替换掉heap中的最小位置。
```
class Solution(object):
    def findKthLargest(self, nums, k):
        from heapq import heappush,heapreplace
        #最大堆
        heap = []
        for i in range(len(nums)):
            if i < k:
                heappush(heap,nums[i])
            else:
                if nums[i] > heap[0]:
                    heapreplace(heap,nums[i])
        return heap[0]
```