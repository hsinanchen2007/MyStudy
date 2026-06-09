1、将所有的path转换为dict，key为'1'-'N'，value为'1'-'N'对应的路径；
2、将1的颜色置为1，从2开始遍历dict；
3、每一次遍历，新建一个颜色集合（[1,2,3,4]），取出key对应的花园代号，遍历代号。如果该代号花园已经有颜色了，取出其颜色，从颜色集合中去掉；如果该花园没有颜色，跳过；全部代号遍历结束后，取颜色集合第一个颜色作为当前key 的颜色，存入结果中；
4、反复计算更新结果，最后输出结果；
Python代码如下：

```python
class Solution(object):
    def gardenNoAdj(self, N, paths):
        """
        :type N: int
        :type paths: List[List[int]]
        :rtype: List[int]
        """
        recorder = {}
        for i in range(1, N+1, 1):
            recorder[str(i)] = []

        for path in paths:
            recorder[str(path[0])].append(path[1])
            recorder[str(path[1])].append(path[0])

        result = [1]
        for i in range(2, N+1, 1):
            colors = [1, 2, 3, 4]
            sub_nodes = recorder[str(i)]
            for sub_node in sub_nodes:
                if sub_node > len(result):
                    continue
                else:
                    if result[sub_node-1] in colors:
                        colors.remove(result[sub_node-1])
            result.append(colors[0])
        return result