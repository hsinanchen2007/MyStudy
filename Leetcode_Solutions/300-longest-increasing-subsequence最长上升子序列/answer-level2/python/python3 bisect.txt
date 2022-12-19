### 解题思路
此处撰写解题思路
最长上升子序列，很明显题目原意子序列的相对顺序是不变的，可以看到原来的示例其实 2，5，7，101  或者 2，3，7，101 都是可以的，但是为什么说是
2，3，7，101 呢，其实这里关注的是长度，和具体的上升子序列没有很大关系，但是这里有暗示的就是3比5小，所以换成了3，18比101小，所以换成了18，最长上升子序列。
进阶方法的复杂度也一再提示我们在遍历nums的时候使用二分法。

引出：
也即是一个空的列表res，我们遍历nums的时候，寻找当前遍历的值在res的坐标，如果坐标小于res的长度，就把这个坐标的值替换为当前遍历的值，坐标大于就append进去。最后查看res的长度就可以了
### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        res = []

        for i in nums:
            pos = bisect.bisect_left(res,i)
            if pos<len(res):
                res[pos]=i
            else:
                res.append(i)
        return len(res)
```