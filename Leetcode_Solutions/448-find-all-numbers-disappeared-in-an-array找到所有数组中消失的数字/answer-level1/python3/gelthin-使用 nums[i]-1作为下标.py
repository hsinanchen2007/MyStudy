### 解题思路
惊呆了，极好的面试题。评论区陈牧远非常优秀的解答，与官方解法一致。

很多个类似这样的题目，考察热点。


官方题解：
#### 1. 使用 hashset
#### 2. 使用 nums[i]-1 作为下标
+ 利用 1<= nums[i]<=n, 推出，0<=nums[i]-1<=n-1, 可以作为数组的下标。如果没有这一条件就要额外想办法
+ 把对应下标位置的数改为负数，nums[abs(nums[i])-1] = - abs(nums[abs(nums[i])-1])
+ 注意到这里 abs(nums[i]) 用 abs 是由于 nums[i]最初必然是正数，但在处理过程中可能被前面数改为了负数
+ 而用 abs(nums[abs(nums[i])-1]) 则是由于可能出现重复数，已经被修改为负数了。

#### 3.使用 liweiwei 题解 同习题 [41. 缺失的第一个正数](https://leetcode-cn.com/problems/first-missing-positive/)
+ 1.利用 1<= nums[i]<=n, 推出，0<=nums[i]-1<=n-1, 可以作为数组的下标。
+ 2.如果 nums[i] != nums[nums[i]-1], 那么就交换，如果已经相同了，就不交换，已经相同，说明有重复值，交换了一次后就会相同。
+ 3.如果少了判相同，会导致 bug.
+ 4.后续遍历判断。

### 代码

```python3
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        # 惊呆了，极好的面试题。评论区陈牧远非常优秀的解答，与官方解法一致
        # 1. 使用 hashmap
        # 2.利用 1<= nums[i]<=n, 推出，0<=nums[i]-1<=n-1, 可以作为数组的下标。如果没有这一条件就要额外想办法
        # 把对应下标位置的数改为负数，nums[abs(nums[i])-1] = - abs(nums[abs(nums[i])-1])
        # 注意到这里 abs(nums[i]) 用 abs 是由于 nums[i]最初必然是正数，但在处理过程中可能被前面数改为了负数
        # 而用 abs(nums[abs(nums[i])-1]) 则是由于 可能出现重复数，已经被修改过了。
        for i in range(len(nums)):  # 若用 for x in nums： 下面原地修改 nums 会导致错误。
            nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1])
        
        res = []
        for i in range(len(nums)):
            if nums[i] > 0:
                res.append(i+1)
        return res




```