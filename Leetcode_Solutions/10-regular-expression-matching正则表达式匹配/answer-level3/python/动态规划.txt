这道题采用动态规划的思想。下面按照动态规划四要素逐一进行考虑：

**状态定义**：$(i,j)$代表第$i$个字符与第$i$个模式字符之前的匹配结果，值为布尔值，代表匹配是否成功，我们需要找到一个正确的映射：
$$
(i,j) \Rightarrow \{0,1\} 
$$
**最终结果**：我们的结果可以表示成$(len(s),len(p))$的值。

**初始化**：由于任何空的$p$都无法匹配任何非空的$s$：故$(*,0)=0$，又因为空串能够和空模式匹配，故$(0,0)=1$，因为任何非空的$p$与空的$s$存在匹配的可能性，所以需要计算$(0,j)$的值，当$j=1$时，无法匹配，故$(0,1)=0$，当$j>1$时，如果为星号，则重复次数取零，即$(0,j)=(0,j-2)$，否则为0。

**状态转移方程**：这道题目的重点在于状态转移方程，在代码中已经列出，概括如下，在状态$(i,j)$：

- 如果当前模式字符不是星号：

  - 如果当前模式字符是点号或者两个字符相等，那么匹配成功：
    $$
    (i,j)=(i-1,j-1)
    $$

  - 否则，匹配失败：
    $$
    (i,j)=0
    $$

- 如果当前模式字符是星号：

  - 如果前一个模式字符能匹配当前字符，即$s[i-1]=p[j-2]$或者$p[j-2]=.$，那么：
    - 匹配零个：$(i,j)=(i,j-2)$；
    - 匹配一个：$(i,j)=(i,j-1)$；
    - 匹配多个：$(i,j)=(i-1,j)$。
  - 如果不能匹配，即强行匹配零个，那么$(i,j)=(i,j-2)$。

整道题目的代码如下：

```python
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        len_s = len(s)
        len_p = len(p)

        # initialization
        res_m = [[False for j in range(len_p + 1)] for i in range(len_s + 1)]

        for i in range(len_s + 1):
            res_m[i][0] = False

        res_m[0][0] = True
        if len_p != 0:
            res_m[0][1] = False

        for j in range(2, len_p + 1):
            if p[j-1] == '*':
                res_m[0][j] = res_m[0][j-2]
            else:
                res_m[0][j] = False

        # iterate
        for i in range(1, len_s + 1):
            for j in range(1, len_p + 1):
                if p[j-1] != '*':
                    if p[j-1] == s[i-1] or p[j-1] == '.':
                        res_m[i][j] = res_m[i-1][j-1]
                    else:
                        res_m[i][j] = False
                else:
                    if p[j-2] == s[i-1] or p[j-2] == '.':
                        res_m[i][j] = res_m[i][j -
                                               1] or res_m[i][j-2] or res_m[i-1][j]
                    else:
                        res_m[i][j] = res_m[i][j-2]

        return res_m[len_s][len_p]
```