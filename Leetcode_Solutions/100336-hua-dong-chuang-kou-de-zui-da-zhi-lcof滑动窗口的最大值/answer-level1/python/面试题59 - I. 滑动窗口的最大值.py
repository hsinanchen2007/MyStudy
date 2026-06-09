### 解题思路
设nums列表长度为lenth，设置一个长度为k的滑动列表test，通过索引i对nums进行遍历。
然后从列表起始开始遍历，遍历到lenth=i+(k-1)结束（因为子列表元素是i-(K-1)共k个元素）。
再设置一个max_list用于存放最大值。

### 代码

```python3
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        max_list = []
        lenth = len(nums)
        if k == 0 or lenth == 0:
            return max_list
        else:
            for i in range(lenth-k+1):
                test = nums[i:(i+k)]
                max_index = max(test)
                max_list.append(max_index)
            return max_list

```