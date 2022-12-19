![kkkk.png](https://pic.leetcode-cn.com/ec48f20e7ef758ace15ed5126e634daff5a8f2e19f270a5a8f85fa9eda07fa6c-kkkk.png)
从上面这个图来看 要获得不重复的，就要把同一层中相同元素去掉。
所以首先对字符串排序

然后同一层剪枝
```

class Solution:

    def __init__(self):
        self.path = []
        self.res = []

    def permutation(self, s: str) -> List[str]:
        # 说的是这里面的结果可能是有重复元素
        # 就是去掉同一层中重复的呗！
        if not s:
            return []
        self.lng = len(s)
        s = ''.join(sorted(list(s)))
        visited = [False for _ in range(self.lng)]
        self.dfs(s, visited)
        return self.res

    def dfs(self, s, visited: List[bool]):
        for i in range(len(s)):
            # 在同一层中进行剪枝
            flag = True
            if i - 1 >= 0 and s[i] == s[i - 1] and visited[i - 1] == True:
                flag = False
            if not visited[i] and flag:
                visited[i] = True
                self.path.append(s[i])
                if len(self.path) == self.lng:
                    self.res.append(''.join(self.path[:]))
                self.dfs(s, visited)
                visited[i] = False
                self.path.pop()
```

