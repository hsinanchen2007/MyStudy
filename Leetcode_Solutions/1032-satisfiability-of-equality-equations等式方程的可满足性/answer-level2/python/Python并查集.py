```
class Solution(object):
    def equationsPossible(self, equations):
        # 先做个索引字典
        p = {chr(97+i):chr(97+i) for i in range(26)}
        # 查找根节点
        def find(x):
            while x<>p[x]:
                x = p[x]
            return x
        # 同类的关系先建立起来
        for s in equations:
            if s[1] == "=":
                p[find(s[3])] = p[find(s[0])]
        # 若矛盾则返回False
        for s in equations:
            if s[1] == "!" and find(s[0]) == find(s[3]):
                return False
        return True
```
