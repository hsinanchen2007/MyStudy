重点：常数空间。 所以：排除用队列BFS的思路。用了队列就是N的空间复杂度。

解： 在每一层的时候把下一层的next连好。 等到了下一层，由于上一层的next已经连好，所以可以root.right.next = root.next.left。

比较简洁易懂的非递归版本。
```
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        # if root is None
        if root is None:
            return 
        
        the_root = root
        
        while root.left is not None:
            next_layer = root.left
            while root.next is not None:
                root.left.next = root.right
                root.right.next = root.next.left
                root = root.next
            root.left.next = root.right
            root = next_layer
        return the_root
```