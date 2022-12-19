#思路如提示，假如有旧组合qw，新字母e就可以插在前中后三个位置组成新组合
```
class Solution(object):
    def permutation(self, S):
        result = [S[0]]   #一个字母时
        for i in range(1, len(S)):
            m = []  #增加字母是新的组合
            for value in result:
                for j in range(len(value) + 1):  #对每个组合进行插值
                    m.append(value[:j] + S[i] + value[j:])  #把接着的新字母S[i]插进去
            result = m  #生成新的组合
        return result

```
