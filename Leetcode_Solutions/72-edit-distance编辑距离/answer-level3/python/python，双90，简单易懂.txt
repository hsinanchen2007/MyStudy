### 解题思路
看题目，这应该是一道典型的双字符串动态规划类题目，跟最长递增子序列题套路相似，但又不完全一致。
解题的关键在于理解这三个操作是**如何影响规划的动态变化的**

定义：`dist[i][j]`为`word1[:i]`与`word2[:j]`完成转换的最小编辑距离，两个字符各增加一个字符，则根据新字符是否相等，有如下情形：
- 若`word1[i] == word2[j]`，新字符相等，无需增加编辑距离即可直接转换，即`dist[i+1][j+1] = dist[i][j]`
- 若两字符不相等，对最后一次采取何种操作分析如下：

    - 插入，最后操作是对word1插入1个字符，意味着`word2[j]`由word1中新插入的字符对应，这是在`word1[:i+1]`和`word2[:j]`完成转换基础上增加一次插入操作实现，即`dist[i+1][j+1] = dist[i+1][n] + 1`

    - 删除，最后操作是对word1删除1个字符，意味着删掉`word1[i]`后两单词匹配，也就是在`word1[:i]`和`word2[:j+1]`完成转换的基础上增加一次删除操作实现，即`dist[i+1][j+1] = dist[i][j+1] + 1`

    - 替换，最后操作是对word1替换1个字符，意味着`word1[i]`替换成`word2[j]`后实现两单词匹配，即在`word1[:i]`和`word2[:j]`完成转换基础上增加一次替换操作实现，即`dist[i+1][j+1] = dist[i][j] + 1`

- 根据动态规划的套路，选择`dist[i+1][j+1]`的最小值必然是三者取最小，从而有转移方程：`dist[i+1][j+1] = min(dist[i+1][j], dist[i][j+1], dist[i][j]) + 1`

**注意事项：**
- `dist[i][j]`是指完成`word1`前i个字符和`word2`前j个字符转换的距离，对应的是`word1[:i] vs word2[:j]`，包括`i=0`或`j=0`时，此时一个单词为空，退化为纯插入或纯删除来完成转换，构成初始状态

- 实际上，定义了`dist`矩阵后，发现每个方格距离仅与其左、上、左上三个值有关，进而又可以仅定义一个一维距离列表和一个辅助列表实现记录，从而优化空间复杂度

- 进一步地，考虑定义的三种操作构成对称关系：在`word1`中删除字符与在`word2`中插入字符其转换效果是一致的，而替换更是对称操作，从而由`word1`转换为`word2`和由`word2`转换为`word1`其最小编辑距离也是一致的。基于此，可根据`word1`和`word2`字符长短进一步优化空间复杂度为最小的那个维度

### 结果
![image.png](https://pic.leetcode-cn.com/d20847e28ea8634abdd2c5394623e37dce1daaa2696b11a12e21b3405c137ee8-image.png)

### 代码

```python3
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        if len(word2)<len(word1):#保证word1是短单词
            word1, word2 = word2, word1
        m, n = len(word1), len(word2)
        dist = list(range(m+1))#word2长度为0时，由不同长度word1转换的编辑距离
        for i in range(1, n+1):
            tmp = [i]*(m+1)#word2长度为i时，由0长度的word1转换的编辑距离
            for j in range(1, m+1):
                if word1[j-1] == word2[i-1]:
                    tmp[j] = dist[j-1]
                else:
                    tmp[j] = min(tmp[j-1], dist[j], dist[j-1]) + 1
            dist = tmp
        return dist[-1]
```
最后，欢迎关注个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)
