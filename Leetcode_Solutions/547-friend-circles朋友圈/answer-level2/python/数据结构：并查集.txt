## 什么是并查集，有什么用？
**并查集是一种数据结构，它的主要用途有以下几点：**  
1. 检查多个相连且无方向无权值的点是否存在环
2. 检查多个相连且无方向无权值的点中有多少集合
  
**若还不明白，请看下图：**  
  
![7.001.png](https://pic.leetcode-cn.com/bd15344e55765d1207663315c3df70d87306124dc49c8e2a91f78c17db2d6933-7.001.png)
- 可以看到 图1 中 2 3 4 彼此相连构成了环，这可以用并查集检测出  
- 图二中则是分成了两个集合，可以使用并查集检测有多少集合  
  
还需要注意图2中两集合之间是不相通的，但假设 4 和 9 相连了，那么我们认为此时只有一个集合  
  
看到这里想必大家已经有点思路了，接下来，我们需要做的只是将思路转换为代码即可
  
![未命名.gif](https://pic.leetcode-cn.com/510a00f7f50065a3b31509127bc23e753241956e145b78e54ccb5fbdc94c0ffc-%E6%9C%AA%E5%91%BD%E5%90%8D.gif)

![未命名.004.png](https://pic.leetcode-cn.com/478148c9d7801f78523d53267e5dd43a2274122a868e8665b3adb50d051fc478-%E6%9C%AA%E5%91%BD%E5%90%8D.004.png)


在此题中，我们只需要遍历正二维数组的左下方或者右上方即可，因为如果 （2，3）是 1，那么（3，2）必然是 1，在使用并查集做题解时，知道一次两个点的关系就足够了。  
  
接下来贴出代码：  
```
class Solution(object):
    def findCircleNum(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        # 声明表示集合的树，用数组表示树，如 parent[5] == -1 表示
        # 5 是某个集合的代表，同时也是树根
        parent = [-1] * len(M)
        # 为各个集合的深度排个序
        rank = dict()
        # 只遍历左下部分
        for i in range(len(M)):
            for j in range(i):
                if M[i][j] == 1:
                    # 如果两人是朋友，就把两人放入同一个集合
                    self.union(i, j, parent, rank)
        ans = 0
        for i in parent: # 查看有多少集合，即多少个朋友圈
            if i == -1:
                ans += 1
        return ans
    
    def findRoot(self, num, parent):
        """
        :num：某个小朋友
        :parent：多个集合树
        一直找到这个小朋友所在集合的代表，即树根
        """
        while parent[num] != -1:
            num = parent[num]
        return num

    def union(self, x, y, parent, rank):
        """
        x，y 表示满足朋友关系的两小朋友
        """
        if x == y: # 表示自己和自己是朋友，这个直接返回
            return
        x = self.findRoot(x, parent) # 找到所在集合的代表，可能就是自己
        y = self.findRoot(y, parent)
        rank_x = rank[x] if x in rank else 0 # 查询该集合目前的深度
        rank_y = rank[y] if y in rank else 0
        if x == y: # 检测到 x, y 已经是在同一个集合了，直接返回
            return
        if rank_x > rank_y: # 这里是做路径压缩的，避免树太深使得 findRoot 函数耗时过多
            parent[y] = x
        elif rank_x < rank_y:
            parent[x] = y
        else:
            parent[x] = y
            rank[y] = 1
```

>大致的解法就是这样了
>搜索订阅号 Apelife
>关注后回复 图解，分享给你leetcode动态图解解题集
>定期为大家分享题解，学习经验，解题思路等