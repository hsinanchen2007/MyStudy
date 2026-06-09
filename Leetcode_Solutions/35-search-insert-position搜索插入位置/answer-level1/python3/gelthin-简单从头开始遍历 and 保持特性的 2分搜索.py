### 解题思路
#### 简单遍历

从头部开始遍历，若 nums[i] < x, 则 x 应该在 i 后面；若 nums[i] 是第一个 >= x 的数, 则不管是恰好相等还是大于，
i 都是应该返回的值。不过这一方法需要注意，就是可能 nums 中所有值都小于 x, 这是一种特例，需要额外处理。

若从尾部开始遍历，对 nums[i]>=x, 则可知 x 应该在当前 nums[i] 之前，对第一个小于 x 的数，返回其原下标 + 1。
不过要注意，可能所有值都小于 x, 这样就要返回 0

#### 另一个解法--有序数组2分搜索

重在搜索元素 或者 搜索特性
首先确定当前初始化搜索空间[i, j] 满足特性： nums[i] < target <= nums[j]（注意这里必然是以侧不带等于号，一侧带等于号）
如果搜索空间初始化就不满足此特性，则不用判断已经可以直接给出结果
然后在搜索过程中需要维持此特性并更新搜索空间：i = mid or j = mid
但注意到，i = mid or j = mid 会使得最终搜索空间长度为 2，
更新 i = mid or j = mid, while 循环到最后，必然有 i == j-1, 也即长度为 2。
长度变化： 4 -> 2 or 3, 3->2, 2->2 
因此，当得知长度为2， 即 mid[i]< target <= mid[i+1] 时，就应该返回 i+1

但这里为了保持 **所谓的特性**，每次即使判断了 mid 也把 mid 保留了下来，导致每次留下了待判断的区间过大，循环次数过高。

其他的题解一般是只要**搜索空间中仍然有解的存在**即可，而不需要保持特性。


看了的题解 [画解算法：35. 搜索插入位置](https://leetcode-cn.com/problems/search-insert-position/solution/hua-jie-suan-fa-35-sou-suo-cha-ru-wei-zhi-by-guanp/) 提供了模板，

排除法， 排除不是解的地方
[用“排除法”（减治思想）写二分查找问题、与其它二分查找模板的比较](https://leetcode-cn.com/problems/search-insert-position/solution/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/) 提供了排除法的思路，非常好。



####  2分代码
```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        
        n = len(nums)
        if nums[0] >= target:
            return 0
        if nums[n-1] < target:
            return n
        i = 0
        j = n-1
        while i<j:  # 保持特性 (nums[i]< target, nums[j]>=target) 开始搜索
            if i==j-1:   # 长度为2时，会死循环
                return j
            mid = int((i+j)/2)  
            if nums[mid] < target:
                i = mid    # 这里很重要，是 mid+1 还是 mid
            elif nums[mid] == target:
                return mid  
            else:
                j = mid   # 是 mid-1 还是 mid
        # 更新 i = mid or j = mid, while 循环到最后，必然有 i == j-1, 也即长度为 2。
        # 长度变化： 4 -> 2 or 3, 3->2, 2->2 
```

#### 从头部遍历代码
```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        for i, x in enumerate(nums):
            if x < target:
                i += 1
            else:
                return i
        else:
            return len(nums)
```