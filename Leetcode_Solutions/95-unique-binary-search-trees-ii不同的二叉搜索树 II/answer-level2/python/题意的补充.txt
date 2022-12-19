题目本身会让人有种歧义

第一遍做的时候，我认为我应该返回这样的列表
```
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
```

但实际上，并不需要。

我们通过debug看到官方解题模板的代码
```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """

def stringToInt(input):
    return int(input)
# 结点转为字符串，层次遍历
def treeNodeToString(root):
    if not root:
        return "[]"
    output = ""
    queue = [root]
    current = 0
    while current != len(queue):
        node = queue[current]
        current = current + 1

        if not node:
            output += "null, "
            continue

        output += str(node.val) + ", "
        queue.append(node.left)
        queue.append(node.right)
    return "[" + output[:-2] + "]"
# 遍历列表内的各个树根，然后对其进行字符串化处理
def treeNodeArrayToString(treeNodeArray):
    serializedTreeNodes = []
    for treeNode in treeNodeArray:
        serializedTreeNode = treeNodeToString(treeNode)
        serializedTreeNodes.append(serializedTreeNode)
    return "[{}]".format(', '.join(serializedTreeNodes))

def main():
    import sys
    def readlines():
        for line in sys.stdin:
            yield line.strip('\n')
    lines = readlines()
    while True:
        try:
            line = lines.next()
            n = stringToInt(line)
            
            ret = Solution().generateTrees(n)
            # 通过调用我们的函数得到ret，然后放进了下面这个函数，用于将根节点所表示的树 用层次遍历的方式来转换为字符串
            out = treeNodeArrayToString(ret)
            print out
        except StopIteration:
            break

if __name__ == '__main__':
    main()
```

可以看到，官方只需要我们返回各种情况的树的根节点列表。 不需要把这些转换成一个层次遍历的列表。 我认为是题意没说清楚。
```
[TreeNode_1, TreeNode_2, ..., TreeNode_N]
```


其实本来我也不会做，知识看官方题解和其他的题解时，觉得很奇怪，最终返回了一堆树根，却不是示例的列表。。