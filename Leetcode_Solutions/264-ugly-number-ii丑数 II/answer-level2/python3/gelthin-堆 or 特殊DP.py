### 解题思路
这里用了一种特殊的 DP 来进行实现。这一题有点像拼凑硬币题 [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/solution/322-ling-qian-dui-huan-by-leetcode-solution/#comment) 1,3,5, 累加 1,3,5，生成所有的可能，但是不知道数之间的大小顺序。

这一题最大的难处在于不确定接下来的最少值是啥，比合并三个有序序列还有难度。


参照官方题解，
#### DP
使用三个指针 i2, i3, i5 指向数组元素， 分别乘以 2,3,5， 然后判断一下这三个数中哪一个小，把小的数加入到数组中。
并且对应于这个数的指针增大1.

#### 堆
首先直接用 python 的堆结构。
然后把取出堆里面最小的那个数，然后 *2，*3，*5 加入到堆中，然后再取出堆中最小的那个元素，*2 *3 *5， 然后加入到堆中。
但从堆中取出数字时，要注意避免重复，使用一个 hashset， 或者判断 nums[i-1] == nums[i]。

python3 的堆模块
``` python3 
from heapq import heappop, heappush
```

``` python3
from heapq import heappop, heappush
class Ugly:
    def __init__(self):
        seen = {1, }
        self.nums = nums = []
        heap = []
        heappush(heap, 1)

        for _ in range(1690):
            curr_ugly = heappop(heap)
            nums.append(curr_ugly)
            for i in [2, 3, 5]:
                new_ugly = curr_ugly * i
                if new_ugly not in seen:  #根本不用入堆，这样更好。
                    seen.add(new_ugly)
                    heappush(heap, new_ugly)
    
class Solution:
    u = Ugly()
    def nthUglyNumber(self, n):
        return self.u.nums[n - 1]
```



### 代码

```python3
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        ## 这一题非常强，既可以用堆, 又可以用 DP
        ugly_nums = [1]
        i2, i3, i5 = 0,0,0
        for i in range(1689):
            new_val = min(ugly_nums[i2]*2, ugly_nums[i3]*3, ugly_nums[i5]*5)
            ugly_nums.append(new_val)
            if new_val == ugly_nums[i2]*2:
                i2 += 1
            if new_val == ugly_nums[i3]*3:
                i3 += 1
            if new_val == ugly_nums[i5]*5:
                i5 += 1
        
        return ugly_nums[n-1]

```