### 解题思路
正则大法好。

### 代码

```python3
class Solution:
    def simplifyPath(self, path: str) -> str:
        # 用栈模拟目录变化过程
        stack = []
        top = -1
        content = path.split('/')
        for val in content:
            if val=="..":
                if top>=0:
                    stack.pop()
                    top-=1
            elif val==".":
                continue
            elif bool(re.match('[a-zA-Z.]+',val)): #是字符串
                stack.append(val)
                top+=1
        # 得到规范路径
        res = "/".join(stack)
        res = "/"+res
        return res

```