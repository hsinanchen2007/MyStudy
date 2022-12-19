```
class Solution:
    def lcaDeepestLeaves(self, root: TreeNode) -> TreeNode:        
        if not root:
            return root
        
        # 广度优先，找到最深的所有叶子节点，存放到memory中； 同时设置parent指针指向父节点
        memory = [root]
        while True:
            next_memory = []
            for node in memory:
                if node.left:
                    node.left.parent = node
                    next_memory.append(node.left)
                if node.right:
                    node.right.parent = node
                    next_memory.append(node.right)
            if next_memory:
                memory = next_memory
            else:
                break

        # 根据前面设置的Paren指针，反向找出叶子节点的唯一公共父节点
        while True:
            if len(memory) == 1:
                return memory[0]
            next_memory = []
            id_set = set()            
            for node in memory:
                parent = node.parent
                if id(parent) not in id_set:
                    id_set.add(id(parent))
                    next_memory.append(parent)
            memory = next_memory
```
