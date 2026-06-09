解题思路：
序列化：层序遍历
反序列化：双指针，i指向上一层，j指向下一层，建立父子关系。

``` python
import sys
class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        import collections
        if root is None:
            return ""
        queue = collections.deque([root])
        result = []
        while queue:
            new_queue = collections.deque()
            while queue:
                curr = queue[0]
                queue.popleft()
                result.append(None if curr is None else curr.val)
                if curr is not None:
                    new_queue.append(curr.left)
                    new_queue.append(curr.right)
            queue = new_queue
        print(result)
        return result
        
 
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        import collections
        if data == "":
            return None
        data = [TreeNode(item) if item is not None else None for item in data]
        root = data[0]
        i = 0
        j = 1
        while i< len(data) and j < len(data):
            if data[i]:
                data[i].left = data[j]
                data[i].right = data[j+1]
                j+=2
                i+=1
            else:
                i+=1
        return root
```
