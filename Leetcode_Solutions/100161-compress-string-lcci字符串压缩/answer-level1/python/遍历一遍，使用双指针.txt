### 解题思路
设置两个指针pre和cur,当pre和cur指向的元素相等时，cur继续向后遍历，当pre和cur指向不同时，pre占到cur位置，cur继续向后遍历，因而每个元素出现的次数为cur-pre。

### 代码

```python
class Solution(object):
    def compressString(self, S):
        """
        :type S: str
        :rtype: str
        """
        if not S: return ''
        pre = 0
        cur = 1
        res = ''

        while cur<len(S):
            if S[cur]==S[pre]:
                cur += 1
            else:
                res += S[pre] + str(cur-pre)
                pre = cur
                cur = pre + 1
        res += S[pre] + str(cur - pre)
        if len(res)>=len(S):
            return S
        return res      
```