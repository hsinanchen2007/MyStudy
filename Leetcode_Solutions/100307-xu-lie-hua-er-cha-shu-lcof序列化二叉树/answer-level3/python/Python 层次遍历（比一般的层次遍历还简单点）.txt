之前写的一个层次遍历还需要有内循环或者打tag来分割，这道题直接输出就行了，难点感觉在于怎么还原，我用了个队列模拟，然后index标记当前的位置

```python
class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        queue, index = [root,], 0
        while index < len(queue):
            node = queue[index]
            if node:
                queue.append(node.left)
                queue.append(node.right)
            index += 1
        
        while index:
            index -= 1
            if queue[index]:
                break
        
        queue = queue[:index + 1]
        return '[' + ",".join(str(node.val) if node else 'null' for node in queue) + ']'

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        vals = [i for i in data[1:len(data) - 1].split(',')]
        if not vals[0] or vals[0] == 'null':
            return None
        
        root, index = TreeNode(int(vals[0])), 0
        queue = [root, ]

        def _transform(val):
            if val == 'null':
                return None
            
            else:
                return TreeNode(int(val))

        while queue:
            node = queue.pop(0)
            if index + 1 < len(vals):
                node.left = _transform(vals[index + 1])
                if node.left:
                    queue.append(node.left)

            if index + 2 < len(vals):
                node.right = _transform(vals[index + 2])
                if node.right:
                    queue.append(node.right)

            index += 2

        return root
```