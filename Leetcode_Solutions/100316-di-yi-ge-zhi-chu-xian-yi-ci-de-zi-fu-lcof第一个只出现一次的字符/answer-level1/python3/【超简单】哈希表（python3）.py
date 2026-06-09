## 思路

- 我们遍历一次求出cnts[i]， 其中cnts[i] 表示  a,b,c....z 出现的次数，换句话说我们`统计每个字母出现的次数`。
- 然后我们从左往右遍历s，找到第一个出现次数为1的即可。 

> 如果题目要求最后一个，我们只需要从右往左遍历，找到第一个出现次数为1的即可。

## 代码


```python
class Solution:
    def firstUniqChar(self, s: str) -> str:
        n = len(s)
        cnts = [0] * 26
        for i in range(n):
            cnts[ord(s[i]) - 97] += 1
        for i in range(n):
            if cnts[ord(s[i]) - 97] == 1:
                return s[i]
        return " "
        
```


**复杂度分析**
- 时间复杂度：$O(N)$，其中N为字符串长度。
- 空间复杂度：$O(N)$，其中N为字符串长度。

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
