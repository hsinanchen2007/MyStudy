




总体思路是二叉树拓展中介节点，让二叉树层数足够保存一层n叉树的数据
转换示意图
![image.png](https://pic.leetcode-cn.com/f92f9a30bbe3f34a8e1b10771c9283d6bf1b9b9ae51e09905da01c85955c2557-image.png)


代码

```

'''
思路
在二叉树中增加中介节点，不存数据，只在最后一层存原来n叉树的数据，
假设某n叉树节点有7个子节点
就把二叉树拓展3层，保证最后一层足够存储n叉树的节点，
用二叉树的冗余空间保持住n叉树的结构

解码时候对二叉树进行层次遍历，当前子树中第一次出现非中介节点的层，这层所有节点就是该
子树根节点对应的n叉树的子节点
'''


from typing import List, Deque
from collections import deque

class Codec:


    # 构建n层二叉树，最后一层节点用提供的节点列表中的节点填充，其他中间节点全部数值填None，作为中介节点使用
    def build_nlayer_bs(self, root_val, cur_layer, total_layers, child_nodes: Deque[TreeNode]) -> TreeNode:
        if cur_layer != total_layers:
            root = TreeNode(root_val)
            root.left = self.build_nlayer_bs(None, cur_layer + 1, total_layers, child_nodes)
            root.right = self.build_nlayer_bs(None, cur_layer + 1, total_layers, child_nodes)
            return root

        else:
            return child_nodes.popleft() if len(child_nodes) > 0 else None

    # Encodes an n-ary tree to a binary tree.
    def encode(self, root: 'Node') -> TreeNode:
        if root is None:
            return None

        child_nodes = deque()
        for node in [self.encode(child) for child in root.children]:
            child_nodes.append(node)

        layers = 0
        while (1 << layers) < len(child_nodes):
            layers += 1

        return self.build_nlayer_bs(root.val, 0, max(1, layers), child_nodes)



    # Decodes your binary tree to an n-ary tree.
    def decode(self, data: TreeNode) -> 'Node':
        if data is None:
            return None

        # 层次遍历把下一层非中介节点全部找到
        que = deque()
        que.append(data)

        layer = 0
        buf = []

        flag = False
        while len(que) > 0:
            buf = []
            node_num = len(que)
            for _ in range(node_num):
                buf.append(que.popleft())
            if layer != 0 and len(buf) != 0 and buf[0].val is not None:
                flag = True
                break

            for node in buf:
                for next in [node.left, node.right]:
                    if next:
                        que.append(next)

            layer += 1

        if flag:
            return Node(data.val, [self.decode(node) for node in buf])
        else:
            return Node(data.val, [])
```
