### 1.标准二分
如果能找到target,那么返回的位置就是target的索引mid,表示在位置mid前 插入target。
*   比如：[1,3,5,7], target = 5 返回的是索引mid:2, 在索引2前插入5-》[1,3,5(新插入的值)，5，7]

但是怎么二分始终找到小于等于target呢？
```python
ans = -1
while low <= high:
    mid = (high+low)//2
    if nums[mid] <= target:
        ans = mid
        low = mid + 1
    else:
        high = mid - 1
return ans
```
上面代码永远返回的是小于等于target的索引：
*   比如:[1,3,5,7],则返回 5的索引 2
*   比如:[1,3,7],则返回，3的索引 1

但是我们在插入时，是索引ans 前插入
*   如果能找到target，比如:[1,3,5,7], 返回的是mid = 2，正好是在索引2的位置前插入target
*   如果找不到target, 比如：[1,3,7], 返回的是mid = 1, 所以此时就需要返回mid + 1 了

所以拆开写，就是下面的（完整）代码
```python [group1-Python]
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        high = len(nums) - 1 
        low = 0
        ### 特殊情况
        if target < nums[0]:
            return 0
        if target > nums[high]:
            return high+1
        ###
        ans = 0
        while low <= high:
            mid = (high+low)//2
            if nums[mid] == target:
                ans = mid
                return ans # 可以化简，return mid
            elif nums[mid] < target:
                ans = mid + 1
                low = mid + 1
            else:
                high = mid - 1
        return ans # 可以化简，return low
        #  return mid+1 则会出错
        #   因为 ans 只在elif 中更新
        #   如果改为mid + 1 , 则mid的值可能会在else中被更新，从而mid+1 != ans
```
PS: 本人也是边学边分享，难免有分析错误的地方，欢迎大家指出，也请大家谅解。
感谢[@athossun](/u/athossun/)的 `mid + 1` 评论的指正

### 2.遍历
遍历
最基础

```python [group2-Python]
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        i = 0
        while i < len(nums):
            if nums[i] < target:
                i +=1
            else:
                break
        return i
```