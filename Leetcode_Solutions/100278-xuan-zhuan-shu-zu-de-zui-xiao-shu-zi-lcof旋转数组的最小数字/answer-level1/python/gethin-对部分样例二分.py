同主站习题 [154. 寻找旋转排序数组中的最小值 II](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/)


### 解题思路
这一题实际上只能对部分样例二分，对有一些样例二分法是无法使用的。




#### 这里使用二分，一定要弄清楚其代表的含义, 从左到右还是从右到左也要清楚
+ 搜索从左到右第一个严格小于 nums[0] 的元素
+ 也可以搜索从左到右 （或从右到左， 由于只有一个）第一个比其左边数严格小的数。
见 [gelthin-线性递减数-二分查找bug](https://leetcode-cn.com/problems/construct-the-rectangle/solution/gelthin-xian-xing-di-jian-shu-by-gelthin/)
从左边和从右边搜索的不同。


#### 但是单纯二分并不对。 
例如，[10,1,10,10,10] 过不了，只取得了 numbers[mid] 值，没有任何规律判断该修改 left 还是 right
#### 还是得同时和两边判断， 需要引入两边值 numbers[left], numbers[right] 的大小关系 


### 代码

```python3
class Solution:
    def minArray(self, numbers: List[int]) -> int:
        n = len(numbers)
        if n==0:
            return False
        if n==1:
            return numbers[0]
        if numbers[0] < numbers[-1]:  # 本来就有序，无法处理
            return numbers[0]


    ## 这里使用二分，一定要弄清楚其代表的含义
    # 搜索从左到右第一个严格 小于 nums[0] 的元素，
    ## 也可以搜索从右到左第一个比其左边更小的数, 似乎也不对。
    # 单纯二分，  [10,1,10,10,10] 过不了，没有任何规律，判断该修改 left 还是 right
    #### 还是得同时和两边判断  

        left, right= 0, n-1  # 
        if numbers[left] == numbers[right]: 
            # 在这种情况下无法通过二分来判断 
            # 这个规则无法判断 [10, 10,10, 1, 10, 10,10] 不知道是缩小left 还是 right
            for i in range(left+1, right+1):
                if numbers[i-1] > numbers[i]:
                    return numbers[i]  # bug 错误输出 number[i-1]
            # 没找到第一个严格变小的数，说明全部相同
            return numbers[left]  
        
        while left < right:# 不可能在二分过程中，出现中间某一段满足 num[left] = num[right]
            if numbers[left] < numbers[right]: #当前全有序，这一分支可能存在
                return numbers[left]           #相当于一个加速过程，如果不写此 下面二分也能处理好
            else: # numbers[left] > numbers[right]:
                mid = left+(right-left)//2
                if numbers[0] <= numbers[mid]:  # 和 numbers[0] 比较，而不是 numbers[left]
                    left = mid+1
                else:
                    right = mid

        return numbers[left]
```