### 解题思路
因为题目要求如果答案不止一个，返回长度最长且字典顺序最小的字符串，所以先对dict排序，然后遍历dict每个元素，判断当前探索的元素是否为所给str的子序列，如果是的话把当前探索元素的长度与索引记录下来，最后返回长度最长，字典顺序最小的索引对应的元素
### 代码

```python
class Solution(object):
    def findLongestWord(self, s, d):
        """
        :type s: str
        :type d: List[str]
        :rtype: str
        """
        def isSubsequence(s, t):
            for i in s:
                if i in t:
                    t = t[t.index(i)+1:]
                else:
                    return False
            return True

        d, index, length = sorted(d), [], []
        for i, v in enumerate(d):
            if isSubsequence(v,s):
                index.append(i)
                length.append(len(v))
        if len(index) == 0:
            return ""
        else:
            return d[index[length.index(max(length))]]

```