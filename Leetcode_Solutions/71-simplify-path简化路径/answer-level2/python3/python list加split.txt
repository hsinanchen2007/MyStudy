思想：主要还是要想到用'/'来分割path得到一个list，遍历list的时候只处理两种情况，情况1：遇到'..'，若res不为空，则删除list的尾元素；情况2：遇到文件名，res直接添加即可，其余的情况不处理。

```
class Solution:
    def simplifyPath(self, path: str) -> str:
        res = []
        for s in path.split('/'):
            if s not in ['', '.', '..']:
                res.append(s)
            elif s == '..' and res:
                res.pop()
        return '/'+'/'.join(res)

```
