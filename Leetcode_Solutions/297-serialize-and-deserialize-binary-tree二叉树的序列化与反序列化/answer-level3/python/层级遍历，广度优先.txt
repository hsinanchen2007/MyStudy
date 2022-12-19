### 解题思路
直观思想：用层级遍历全保留当前层每个节点的子节点，无论其子节点是否为空。但在下一层中仅处理不为空的节点。
#### 序列化：
序列化相对简单，直接用层级遍历保存即可，这里为了方便反序列化时的判断，采取嵌套列表的数据结构保存序列化后的结果，其中：
- 列表的每个元素为一个子列表，代表当前层的所有元素
- 只要节点不为空，则将其左右节点值都保留进下一层的结果列表中，空值标记为null
- 下一层节点仅处理那些不为空的节点
#### 反序列化
根据反序列化的结果形式，因为结果是一个嵌套列表，列表的每个元素是一个子列表且代表一层的节点取值，则当结果列表长度为1时，说明只有根节点为空，否则需进行遍历处理：
- 首先完成根节点的赋值，如果根节点为空，则直接返回；否则保存进待处理列表，这里待处理列表是指待添加左右节点
- 用一个nodes列表表示当前待处理的节点，其中的每个节点都是不为none的有效节点
- 取出对应的所有节点取值，且节点取值的个数必然是nodes长度的2倍，所以1对2的判断添加左右节点即可

### 结果
![image.png](https://pic.leetcode-cn.com/d0c40550d873309705a250296070882078d3d79fa517c546ae84888d76cf0f6a-image.png)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        data = []
        nodes = [root]
        while nodes:###层级遍历，每层保存为一个子列表，方便反序列化
            data.append([node.val if node else 'null' for node in nodes])#若节点为none，保存为null
            nodes = [n for node in nodes if node for n in [node.left, node.right]]#节点不为None，则将其左右子节点都加入下一层处理，无论该子节点是否存在
        return data

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        root = TreeNode(data[0][0]) if len(data)>1 else None#如果data列表仅有一个元素说明root为空
        if not root:
            return root
        nodes = [root]
        for vals in data[1:]:##从第二层开始，将数据添加为前一层的子节点
            for i in range(len(nodes)):
                nodes[i].left = TreeNode(vals[i*2]) if vals[i*2] != 'null' else None
                nodes[i].right = TreeNode(vals[i*2+1]) if vals[i*2+1] != 'null' else None
            nodes = [n for node in nodes  for n in [node.left, node.right] if n]#进保留下一层中不为None的节点作为待处理节点
        return root
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
```
