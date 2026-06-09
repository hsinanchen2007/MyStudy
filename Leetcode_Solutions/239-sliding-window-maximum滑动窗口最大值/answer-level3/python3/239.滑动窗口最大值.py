### 解题思路
- 维护一个window,window的第一个元素是当前窗口中最大值的index;
- 通过window[0]+k == i可以判断window已经不属于当前窗口了，应该弹出
- 为了保证window[0]是当前窗口的最大值，新进来的元素需要与窗口中元素比较，弹出小于新元素的所有元素（新元素又大，又合法，前面的小数不用保留）
- 这样，每一次滑动以后，就去取window[0],获取nums[window[0]]

### 代码

```python3
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums:return nums
        window = []
        res = []
        for index,num in enumerate(nums):
            if index>=k and window[0]+k==index:
                window.pop(0)
            while window and nums[window[-1]]<=num:
                window.pop()
            window.append(index)
            if index>=k-1:
                res.append(nums[window[0]])
        return res

```