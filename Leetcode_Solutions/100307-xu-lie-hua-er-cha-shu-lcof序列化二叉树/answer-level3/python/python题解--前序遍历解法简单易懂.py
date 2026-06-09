### 基于前序遍历的解法
![image.png](https://pic.leetcode-cn.com/c4c46c90c36c2b165bbd3c5894ac9eb3872e3ff3833ace5e0e11719804cc3aa1-image.png)

- 总的思路就是用前序递归建立编码阶段,再使用递归反向生成,下面为具体步骤.
![image.png](https://pic.leetcode-cn.com/ebf4cf07f16013af5723a1b3298e5c1c75f9fb16619e10a71ae49dfd97701d23-image.png)
- 我们给定一个题目示例中的二叉树, 使用递归的方式进行前序遍历,当子节点的值为空时,我们存储一个特殊符号`$`,代表子节点为空.
- 生成的前序序列为`1,2,$,$,3,4,$,$,5,$,$`,这就是我们的编码部分工作
- 下面是解码的部分也就是反向生成二叉树的过程,也是这题最主要的过程:
- 同样我们也是利用递归的形式进行反向的输出,我们可以看到上面生成的前序遍历,`1`代表了头结点,继续访问下一个`2`,它是`1`的左孩子,继续遍历到两个`$`,这根据我们前序遍历的想法,它们是节点`2`的左右孩子,也就是空.继续遍历到`3`,它是`1`的右孩子,............一直遍历下去,这个过程可以写成一个递归过程

### 代码

```python
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
        if not root:
            return []
        result = []
        def encodes(root):
            if not root:
                result.append('$')
                return
            result.append(root.val)
            encodes(root.left)
            encodes(root.right)
        encodes(root)
        return result

                
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if not data:
            return []
        index = [0] #全局变量
        def decodes(data):
            if data[index[0]] == '$':
                index[0] += 1
                return None
            node = TreeNode(data[index[0]])
            index[0] += 1
            node.left = decodes(data)
            node.right = decodes(data)
            return node
    
        return decodes(data)
        



        
        
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
```