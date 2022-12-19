### 解题思路
此处撰写解题思路
step1: 找到每个字母的起始位置和终止位置

以`S = "ababcbacadefegdehijhklij"` 为例：
得到这样的一个位置信息
`positions = [[0, 8], [1, 5], [4, 7], [9, 14], [10, 15], [11, 11], [13, 13], [16, 19], [17, 22], [18, 23], [20, 20], [21, 21]]`
如果可视化这些位置信息
![image.png](https://pic.leetcode-cn.com/d0d4e3e57ce2efb7ab2fe54c0b81c6cb77b64dcbf7c86ff1a96b13ad3a8d20fa-image.png)

step2: 划分片段
可以清楚的看到，这些字母分布在三部分上，只要找到每部分的最小开始min_start和最大结束max_end
(原理类似于[https://leetcode-cn.com/problems/non-overlapping-intervals/description/](453.无重叠区间))

### 代码

```python3
class Solution:
    def partitionLabels(self, S) :
        d = dict()
        # step1: 找到位置信息
        for i in range(len(S)):
            if S[i] not in d.keys():
                d[S[i]] = [i,i]
            else:
                d[S[i]][1] = i
        positions = sorted(list(d.values()), key=lambda x:x[0])
        # step2: 找到字母片段
        res, min_start, max_end = [], 0, 0
        for x_start, x_end in positions:
            if x_start > max_end:
                res.append(max_end-min_start+1)
                max_end = x_end
                min_start = x_start
            elif x_end > max_end:
                max_end = x_end
        res.append(max_end-min_start+1)
        return res
```