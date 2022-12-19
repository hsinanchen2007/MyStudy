### 解题思路
题目解读：最多片段，且同一字母只在一个片段。等价于从左第一位a，找最后a所在位置。中间片段即为最小片段
难点：片段中间的其他字母会扩展区间右边界。
解决问题：右边界什么时候截止呢？
对于每一字母，去找这个字母最后一次出现位置用来更新区间右边界。遍历到右边界时，该片段就截止。

1.用字典+枚举法来更新S的最大下标：last{a:b for a,b in enumerate(S)}，这段代码理解为：
last = {}
for a,b in enumerate(S):
    last[b] = a

print last
》 {u'a': 8, u'c': 7, u'b': 5, u'e': 15, u'd': 14, u'g': 13, u'f': 11, u'i': 22, u'h': 19, u'k': 20, u'j': 23, u'l': 21}
2.用start,end表示当前片段首尾，若字母最大下标大于end，则扩大end=last[j],当i遍历到end时结束当前片段，进入下一个。
### 复杂度分析
时间复杂度O(N)
空间复杂度O(N))
### 代码

```python
class Solution(object):
    def partitionLabels(self, S):
        last{a:b for a,b in enumerate(S)}
        ans = []
        start,end = 0,0
        for i,j in enumerate(S):
            end = max(end,last[j])
            if i == end:
                ans.append(i - start + 1)
                start = i + 1
        return ans
```