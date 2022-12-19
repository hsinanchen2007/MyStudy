### 解题思路

根据第一个例子：

richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]

首先构造这个图，我们同时要保存最上面的人，也就是最富的人，把 ans 初始化每个人自己。

![icon (1).svg](https://pic.leetcode-cn.com/3e84b283f8d48af32b166775186193be155cdb0aeead215448698ac703754218-icon%20\(1\).svg)

然后我们通过广度优先遍历，一层一层的往下，更新 ans


![icon (2).svg](https://pic.leetcode-cn.com/03b60f283f4fc3703799b5d7751231b24c83e137a75c60b8598f1cd169566b8d-icon%20\(2\).svg)


![icon (4).svg](https://pic.leetcode-cn.com/9f9d14734b19ec4d33e6b21334dccc36f374cc38dadd26f132b2fc94129c9bf9-icon%20\(4\).svg)






### 代码

```python
class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        n = len(quiet)
        poorer = [[] for i in range(n)]
        toper = set()
        for x, y in richer:
            poorer[x].append(y)
            if y in toper: toper.remove(y)
            toper.add(x)
        ans = [i for i in range(n)]
        while toper:
            new_set = set()
            for rich in toper:
                for poor in poorer[rich]:
                    if quiet[ans[poor]] > quiet[ans[rich]]:
                        ans[poor] = ans[rich]
                    new_set.add(poor)
            toper = new_set
        return ans
```


欢迎来我的博客： [https://codeplot.top/](https://codeplot.top/)
我的博客刷题分类：[https://codeplot.top/categories/%E5%88%B7%E9%A2%98/](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)