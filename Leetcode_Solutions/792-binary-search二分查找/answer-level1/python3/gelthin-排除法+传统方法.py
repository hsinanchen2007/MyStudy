### 解题思路

[用“排除法”（减治思想）写二分查找问题、与其它二分查找模板的比较](https://leetcode-cn.com/problems/search-insert-position/solution/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/)


### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        if n == 0:
            return -1
        i, j = 0, n-1
        while i<j:
           # bug mid = (i+j)>>2
            mid = (i+j)//2        
            if nums[mid] < target:
                i = mid+1
            else: # 这里比起常规的方法其实少比较一次，虽然缩小空间也变小了, 不是 j = mid-1
                j = mid
        if nums[i] == target:
            return i
        else:
            return -1
```

#### 分治法 + 传统教科书方法的混合体 但这个不一定正确， 见题解[69. x 的平方根](https://leetcode-cn.com/problems/sqrtx/solution/cai-yong-pai-chu-fa-by-gelthin/)
```python3   # 补上判断 nums[mid] == target, 
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        if n == 0:
            return -1
        i, j = 0, n-1
        while i<j:
           # bug mid = (i+j)>>2
            mid = (i+j)//2        
            if nums[mid] < target:
                i = mid+1
            else: 
                if nums[mid] == target:  # 如果补上这一次比较，缩小空间又回来了，
                    return mid    # 一般当搜索空间很大，很难最开始就能碰到 target, 故这个比较效率低。
                else:             # 但万一中了，就可以直接返回，接下来不用做
                    j = mid-1  # 但这里不一定正确
        if nums[i] == target:
            return i
        else:
            return -1
```


#### 若继续把 i<j 变为 i<=j, 则变回了原来的传统的方法，不过要思考返回 i 还是 j
传统方法：


