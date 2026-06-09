### 解题思路
对于本题，首先要定位出前K个最大的元素，然后再找出第K个大的元素；
实现上述思路的方案，经典的有快排和大(小)顶堆两种思路；

本文中采用大顶堆的思路，但是有点改变：
- 本文中不去维护前K个最大元素的大顶堆，而是维护前(N-K+1)个最小元素的小顶堆；
- 并且，为了避免后续的排序操作，在维护小顶堆的时候，将原来的元素乘以-1，这样的话，相当于小顶堆的堆顶元素即是我们要找的第(N-K+1)小，第K大的元素；

思路来源：[最小的k个数，官方题解](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/solution/zui-xiao-de-kge-shu-by-leetcode-solution/)

感谢

### 代码

```python3
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        lgth = len(nums)
        if k == 0 or lgth == 0:
            return []

        hp = [-x for x in nums[:lgth-k+1]]
        heapq.heapify(hp)
        for i in range(lgth-k+1, lgth):
            if nums[i] < -hp[0]:
                heapq.heappop(hp)
                heapq.heappush(hp, -nums[i])
        
        return -hp[0]


```