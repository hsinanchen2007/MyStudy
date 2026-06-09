30/30 cases passed (40 ms)
Your runtime beats 84.63 % of python3 submissions
Your memory usage beats 63.32 % of python3 submissions (13.2 MB)

对于任意一个字符串，给出其对应的特征值, 通过比较特征值是否相同来判断是否同构

```
class Solution:
    def eigenValues(self, x):#返回一个字符串的特征值
        L, p, k = {}, 0, ''
        for i in x:
            if i not in L:
                p += 1
                k, L[i] = k+str(p), str(p)
            k += L[i]
        return k
    def isIsomorphic(self, s, t):
        return self.eigenValues(s) == self.eigenValues(t)
```
## 思路

特征值: 每个字符都有一个各不相同的代号, 这些代号按照字符串中字符的顺序排列组成了特征值

初始特征值为"", 字典L初始值为空
若字符串不为空, 则将第一个字符的代号设为"1"接到特征值末尾并加入字典
往后每遇到一个字符, 若其在字典里, 取出对应代号并接到特征值末尾, 若不在, "代号+1"接到特征值末尾并加入字典

比如对于字符串"apple", 其特征值为"12234"



