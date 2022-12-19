# 暴力法

```
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n=len(nums)
        temp=nums[0:k]
        res=[max(temp)]

        for i in range(k,n):
            temp=nums[i-k+1:i+1]
            res.append(max(temp))
        return res
```

```
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        import heapq
        temp=nums[0:k]
        res=[max(temp)]
        n=len(nums)
        for i in range(k,n):
            temp=nums[i-k+1:i+1]
            heapq.heapify(temp)
            a=heapq.nlargest(1,temp)
            res.append(a[0])
        return res
        

        
```

看到这个题第一反应是以为用优先队列来做，后来仔细一下发现不可行，这样跟暴力法的时间复杂度是一样的。

# 双端队列
```
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        temp=[nums[0]]
        res=[max(nums[0:k])]
        for i in range(1,k):
            if nums[i]>temp[-1]:
                temp.append(nums[i])
        n=len(nums)
        for i in range(k,n):
            if nums[i-k]>=temp[0]:
                del temp[0]
            if not temp:
                temp.append(max(nums[i-k+1:i+1]))
            elif nums[i]>=temp[-1]:
                temp.append(nums[i])
            res.append(temp[-1])
        return res
```
就是一个简单的窗口滑动的问题，遇到更大的就加进来，同时出队得那一段也是遇到出队元素更大就出队，然后稍微处理一下边界条件就ok了。