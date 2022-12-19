### 解题思路
传统方法：遍历压缩
（1）以每一个新出现的字符为标志位 basis，记录该字符出现的次数；
（2）保存 字符与其出现的次数；
（3）循环直至遍历到字符串S的最后一位。
返回结果：比较原字符串的长度与压缩字符串的长度，
len(S) < len(compress)，返回原字符串；否则，返回压缩字符串。

### 代码

```python
class Solution(object):
    def compressString(self, S):
        """
        :type S: str
        :rtype: str
        """
        compress = []
        if len(S)==0: 
            return S
        basis, end = S[0], S[0]
        cnt = 1
        for i in range(1, len(S)):
            end = S[i]
            if end == basis:
                cnt += 1
            else:
                compress.append(basis)
                compress.append(str(cnt))
                cnt = 1
                basis = end
        compress.append(basis)
        compress.append(str(cnt))
        return "".join(compress) if len(compress)<len(S) else S

```