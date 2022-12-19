### 解题思路
此处撰写解题思路

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
        if root is None:
            return '#'
        else:
            return str(root.val)+','+self.serialize(root.left)+','+self.serialize(root.right)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        data=data.split(',')
        m=[]
        if data[0]=='#':
            return None
        for e in data:
            if e!='#':
                n=[TreeNode(e),0]
                m.append(n)
            else:
                p=m[-1]
                n=[None,1]
                while p[1]==1:
                    p[0].right=n[0]
                    n=m.pop()
                    if len(m)==0:
                        return n[0]
                    else:
                        p=m[-1]
                p[0].left=n[0]
                p[1]=1

                    
                    

                    

                


                
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
```