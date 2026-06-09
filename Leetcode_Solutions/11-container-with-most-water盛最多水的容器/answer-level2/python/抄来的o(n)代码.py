### 解题思路
从两端分别往中间汇聚。
之所以不会漏掉最大的，是因为每次移动的都是短边。
为什么移动短边而不是长边，因为底边一直在变短，高取决于短边，只有当短边变长才可能得到更大的值。
此处的问题在于为什么移动短边这种操作不会跳掉较大的值，这是因为如果短边不动的情况下移动长边时，得到的值一定是全小于初始的那个状态的，所以这些状态可以全部跳过。
以上
### 代码

```python3
class Solution:
    def maxArea(self, height: List[int]) -> int:
        # 朴素的超时做法
        # max_v = 0
        # left = []
        # left.append(0)
        # for i in range(1,len(height)):
        #     for j in range(0,len(left)):
        #         max_v = max(max_v, min(height[left[j]], height[i])*(i-left[j]))
        #     if height[i] > left[-1]:
        #         left.append(i)
        # return max_v
        i, j, max_v = 0, len(height)-1, 0
        while i < j:
            if height[i] < height[j]:
                max_v = max(max_v, height[i]*(j-i))
                i += 1
            else:
                max_v = max(max_v, height[j]*(j-i))
                j -= 1
        return max_v
```