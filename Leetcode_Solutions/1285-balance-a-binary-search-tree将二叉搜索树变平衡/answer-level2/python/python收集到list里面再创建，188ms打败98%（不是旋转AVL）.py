```
def collect(root, result):
    if root is not None:
        collect(root.left, result)
        result.append(root)
        collect(root.right, result)

def bulid(all_nodes, start, end):
    if end <= start:
        return None
    if end - start == 1:
        all_nodes[start].left = all_nodes[start].right = None
        return all_nodes[start]

    mid = (start + end) / 2
    node = all_nodes[mid]
    node.left = bulid(all_nodes, start, mid)
    node.right = bulid(all_nodes, mid+1, end)
    return node

class Solution(object):
    def balanceBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        result = []
        collect(root, result)
        return bulid(result, 0, len(result))
```
AVL手撕好像太累了（- -..）
ps:左闭右开表示区间，真香。