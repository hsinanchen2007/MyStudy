速度击败90%
内存击败4%

在我的本地IDE进行测试，样例
equations = [["a","b"],["b","c"],["bc","cd"]]
values = [1.5,2.5,5.0]
queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
能够的到正确得结果 [3.75, 0.4, 5.0, 0.2]

但是提交后  显示错误，应该是哪里精度有问题  1.5存为2.0了
导致提交结果为 [6.0,0.33333,5.0,0.2]
差了半天，不知道在哪里精度损失，求指导

感谢 @Leon_liang的帮忙
https://support.leetcode-cn.com/hc/kb/article/1194344/，大体意思就是leecode对所有测试case只初始化一次类
# 添加初始化
        self.dictfathernode = {}
        self.dictnodeval = {}
```
class Solution(object):
    dictfathernode = {}
    dictnodeval = {}

    # 初始化节点
    def init(self, node):
        # 当节点已经存在时
        if node in self.dictfathernode:
            return
        self.dictfathernode[node] = node
        self.dictnodeval[node] = 1.0

    # 查询父节点 同时进行值的更新
    # 使用递归 同时对路径进行压缩   将每个节点连接到与父节点的关系
    def getfather(self, node):
        if self.dictfathernode[node] == node:
            return node
        # 递归得到父节点
        fa = self.getfather(self.dictfathernode[node])
        # 递归的更新当前节点得值  前父节点关系值 * 更新后得父节点值
        self.dictnodeval[node] = self.dictnodeval[self.dictfathernode[node]] * self.dictnodeval[node]
        # 将节点的父节点更新为最父节点
        self.dictfathernode[node] = fa
        return fa

    # 合并两个node 将大的合并到小的 保证根为1.0
    def merge(self, node1, node2, val):
        node1f = self.getfather(node1)
        node2f = self.getfather(node2)

        # 两个节点的根相同时不合并
        if node1f == node2f:
            return
        # 分别计算出到node2上  用于比较根的相对大小
        val1 = self.dictnodeval[node1]
        val2 = self.dictnodeval[node2]

        # 当node2的根比较小时  合并根node1到2上
        val1buf = val2 * val
        if val1buf > val2:
            self.dictfathernode[node1f] = node2f
            self.dictnodeval[node1f] = val1buf / val1
        # 将 1 合并到 2上
        else:
            self.dictfathernode[node2f] = node1f
            self.dictnodeval[node2f] = val1 / val1buf


    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        # 每一次使用前需要初始化
        self.dictfathernode = {}
        self.dictnodeval = {}
        # 创建并查集
        for i in range(len(equations)):
            # 初始化节点
            self.init(equations[i][0])
            self.init(equations[i][1])
            self.merge(equations[i][0], equations[i][1], values[i])
        ans = []
        for i in queries:

            # 如果 两个字符均在字典中存在
            if i[0] in self.dictfathernode and i[1] in self.dictfathernode:
                # 如果拥有相同的根节点 则可以计算关系
                if self.getfather(i[0]) == self.getfather(i[1]):
                    ans.append(self.dictnodeval[i[0]] / self.dictnodeval[i[1]])
                else:
                    ans.append(-1.0)
            else:
                ans.append(-1.0)
        return ans

# equations = [ ["a", "b"], ["b", "c"], ["b", "e"] ]
# values = [2.0, 3.0, 4.0]
# queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]
equations = [["a","b"],["b","c"],["bc","cd"]]
values = [1.5,2.5,5.0]
queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
solution = Solution()
result = solution.calcEquation(equations, values, queries)
print(result)
```
