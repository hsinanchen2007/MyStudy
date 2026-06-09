class Solution:
    def connect(self, root: 'Node') -> 'Node':
        # res = []]
        if not root:
            return root
        root.next = None
        cur_level = [root]
        while cur_level:
            next_level = []
            tmp_node = None
            for cur_node in cur_level:
                if cur_node.left:     
                    next_level.append(cur_node.left)
                    cur_node.left.next = cur_node.right
                    if tmp_node:
                        tmp_node.next = cur_node.left
                        tmp_node = None
                if cur_node.right:
                    next_level.append(cur_node.right)
                    tmp_node = cur_node.right
            cur_level = next_level
        return root