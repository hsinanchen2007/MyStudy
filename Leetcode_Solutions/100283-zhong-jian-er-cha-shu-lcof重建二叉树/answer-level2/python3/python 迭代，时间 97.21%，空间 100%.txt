```
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        """
        迭代，用栈来保存元素。
        按照前序来生成结点，每个当前节点需要根据中序顺序判断其在上一节点（栈顶元素）的前还是后（构建哈希表加快查询）：
        1、当前元素是栈顶元素的中序顺序之前：连接二者，并把当前元素入栈。
        2、当前元素是栈顶元素的中序顺序之后：必须明确当前元素不一定是栈顶元素的左子节点，必须连续出栈直到栈顶元素在中序中的顺序比当前元素靠前，
           此时最后出栈的元素的右子节点就是当前元素，连接二者，并把当前元素入栈。
        """
        if len(preorder) == 0:
            return None

        table = {}
        for i, x in enumerate(inorder):
            table[x] = i
        
        stack = []
        cur = 1
        root = TreeNode(preorder[0])
        stack.append(root)
        while cur < len(preorder):
            last_node = stack[-1]
            cur_node = TreeNode(preorder[cur])
            
            # 当前元素是栈顶元素的中序顺序之前
            if table[cur_node.val] < table[last_node.val]:
                last_node.left = cur_node
            
            # 当前元素是栈顶元素的中序顺序之后
            else:
                # 关键：连续出栈直到栈顶元素在中序中的顺序比当前元素靠前
                while stack and table[cur_node.val] > table[stack[-1].val]:
                    last_node = stack.pop()

                last_node.right = cur_node

            stack.append(cur_node)    # 不管怎样都要入栈
            cur += 1

        return root
```
