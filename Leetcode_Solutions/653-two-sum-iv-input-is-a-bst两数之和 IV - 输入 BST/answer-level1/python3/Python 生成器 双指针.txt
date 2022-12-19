```
def inOrder(root):
    if root is None:
        return
    for i in inOrder(root.left):
            yield i
    yield root
    for j in inOrder(root.right):
        yield j

def inReverse(root):
    if root is None:
        return
    for i in inReverse(root.right):
            yield i
    yield root
    for j in inReverse(root.left):
        yield j

class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        if root is None:
            return False
        sortSequence = inOrder(root)
        reverseSequence = inReverse(root)
        fn = next(sortSequence).val
        bn = next(reverseSequence).val
        while fn < bn:
            try :
                s = fn + bn
                if s == k :
                    return True
                elif s < k:
                    fn = next(sortSequence).val
                else:
                    bn = next(reverseSequence).val
            except StopIteration:
                return False
        return False
```
