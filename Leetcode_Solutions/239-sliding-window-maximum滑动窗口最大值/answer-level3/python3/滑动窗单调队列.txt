### 解题思路
构建单调队列：队列中存的是元素index（用于pop出窗口的元素）
    每当append一个新元素时:
        1. 根据窗口的left和right，将出窗口的元素数的索引从【队首】pop掉 => 保证索引是有序的，如果需要pop，那一定在队首
        2. 【队尾】append新元素，将原队列中小于新元素元素的项删除  => 删完之后，可以保证队列中索引对应的值是有序的（降序）
        
每个元素只会被 popleft()或者pop() 和 append()一次 O(2*n)，加上滑动窗end遍历一次 => 因此总体时间复杂度是O(3*n)

### 代码

```python3
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if nums==[]: return []
        # O(N*K)
        # return [max(nums[i:i+k]) for i in range(len(nums)-k+1)]
        '''
        在一堆数字中，已知最值：
            若给队列中新增一个数，求极值的时间复杂度是。O(1)
            若从队列中删除一个数，求极值必须遍历所有数重新找最值。O(K)
        '''
        # 构建单调队列：队列中存的是元素index（用于pop出窗口的元素）
        # 每当append一个新元素时:
        #   1. 根据窗口的left和right，将出窗口的元素数的索引从【队首】pop掉 => 保证索引是有序的，如果需要pop，那一定在队首
        #   2. 【队尾】append新元素，将原队列中小于新元素元素的项删除  => 删完之后，可以保证队列中索引对应的值是有序的（降序）
        
        ## 每个元素只会被 popleft()或者pop() 和 append()一次 O(2*n)， 加上滑动窗end遍历一次 => 因此总体时间复杂度是O(3*n)
        from collections import deque
        # 新增元素nums[i], 更新滑动窗单调队列
        def updateDeque(dq, i):
            # 若队首元素出window，则pop队首
            if dq and dq[0] <= i-k:
                dq.popleft()
            # 将小于nums[i]的元素索引删除 => 保证降序
            while dq and nums[dq[-1]] < nums[i]:  # dq本身降序，依次从队尾删除即可
                    dq.pop()
            dq.append(i) # append新元素至队尾
        # 
        res = []
        dq = deque()
        for end in range(len(nums)):
            updateDeque(dq, end)
            if end >= k-1:
                res.append(nums[dq[0]])
        return res
        
```