### 解题思路
学习**官方题解**

### 代码

```python
##### 感谢官方题解
#递归深度设置
import sys
sys.setrecursionlimit(100000)
#长度为n时最后保留的元素f(n,m)
def f(n, m):
    if n == 0:
        return 0
    x = f(n - 1, m)
    return (m + x) % n

class Solution:
    def lastRemaining(self, n, m):
        return f(n, m)

#### 超时
# class Solution(object):
#     def lastRemaining(self, n, m):
#         nums = [x for x in range(n)]
#         ln = len(nums)
#         #返回的是一个已经经过修改排序后的数组，找到值为0的索引
#         ans = self.delandsort(nums,m,ln)
#         return ans.index(0)


#     def delandsort(self,nums,m,ln):
#         if ln == 1:
#             return
#         else:
#             k = (m-1) % ln
#             #删除对应元素
#             for i in range(len(nums)):
#                 if nums[i] == k:
#                     #为了找到最后剩余的那个元素，将删除元素换为inf，这样最后剩余元素的值只需找到序号为0对应的索引值即可
#                     nums[i] = float('inf')
#                     break
#             #排序
#             for i in range(len(nums)):
#                 nums[i] = (nums[i] - k - 1) % ln
#             ln -= 1
#             self.delandsort(nums,m,ln)
#             return nums
        
```