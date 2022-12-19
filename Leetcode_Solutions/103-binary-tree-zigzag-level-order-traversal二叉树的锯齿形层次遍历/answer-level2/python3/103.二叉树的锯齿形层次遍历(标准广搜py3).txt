class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        
        if root is None:
            return []
        
        result = []
        count = 1
        #1.创建队列
        queue = []
        queue.append(root)
        #2.while循环，队列不为空时，进行层次遍历
        while queue:
            size = len(queue)
            level = []
            for i in range(size):  #遍历一层
                node = queue.pop(0)
                level.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            if count%2 == 0:       #偶数层反转
                level.reverse()
            count += 1
            result.append(level)
            
        return result