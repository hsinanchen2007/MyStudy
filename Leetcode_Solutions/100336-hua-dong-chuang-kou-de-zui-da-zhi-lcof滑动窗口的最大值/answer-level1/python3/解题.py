### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxSlidingWindow(self, nums, k):
        if nums == []:
            return []
        start = 0
        end = k - 1
        length = len(nums)
        maxValueList = []
        while end <= length - 1:
            value = max(nums[start:end + 1])
            maxValueList.append(value)
            start += 1
            end = start + k - 1
        else:
            return maxValueList
```
解题思路：
1 特殊情况下即nums=[]时，直接返回[]
2 设置start,end变量，代表窗口区间内的开始和结束索引
   在此基础上，然后比较区间最大值，加入列表中，最后返回