![image.png](https://pic.leetcode-cn.com/9c0f2956d700f3567378036d874a4c9927b7cea8c1681d3af616cacb56e02c7f-image.png)


```
class FileSystem:

    def __init__(self):
        self.m = {}

    def createPath(self, path: str, value: int) -> bool:
        idx = path.rfind('/')
        if idx == -1:
            return False

        if idx != 0 and path[:idx] not in self.m:
            return False

        if path in self.m:
            return False

        self.m[path] = value
        return True

    def get(self, path: str) -> int:
        if path not in self.m:
            return -1
        return self.m[path]
```
