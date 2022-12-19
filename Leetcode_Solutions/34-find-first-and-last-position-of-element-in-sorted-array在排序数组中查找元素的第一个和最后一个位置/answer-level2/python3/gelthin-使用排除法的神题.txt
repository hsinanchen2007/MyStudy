### 解题思路
本题可以分为两个子问题:
+ 1.搜索第一个为target值的下标 left
+ 2.搜索最后一个为target值得下标 right

似乎搜索不能同时维持两个下标，我的解决方法如下, 首先在[0,n-1]中搜索 left, 然后判断一下 nums[left] == target
接着，在[left, n-1]范围内搜索right, 最后返回 right.

只是在搜索left 和right 时要使用不同的判断策略，以及采用不同的 mid

#### 搜索 left
``` python3
while a<b:
    mid = a + (b-a)//2
    if nums[mid]<target:  # 找左边第一个，因此，不断排除左边的区间
        a = mid+1
    else:
        b = mid
```

#### 搜索 right
``` python3
while a<b:
    mid = a + (b-a+1)//2   # 找右边第一个，因此不断排除右边的区间
    if nums[mid]>target:   # 若这里再写 nums[mid]<target, 虽然没错，但没有效果, 搜索空间不会缩写,陷入死循环
        b = mid-1
    else:
        a = mid
```

### 代码

```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        if n == 0:
            return [-1, -1]
        if n == 1:
            if nums[0] == target:
                return [0,0]
            else:
                return [-1,-1]
        # find left
        a, b = 0, n-1
        while a<b:
            mid = a + (b-a)//2
            if nums[mid]<target:
                a = mid+1
            else:
                b = mid
        if nums[a] != target:
            return [-1,-1]
        else:
            left = a
            a, b = a, n-1
            while a<b:
                mid = a + (b-a+1)//2
                if nums[mid]>target:   #若这里再写 nums[mid]<target, 虽然没错，但没有效果, 搜索空间不会缩写
                    b = mid-1
                else:
                    a = mid
            right = b
            return [left, right]
```