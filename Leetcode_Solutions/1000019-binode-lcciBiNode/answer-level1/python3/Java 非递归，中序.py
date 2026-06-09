```
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode convertBiNode(TreeNode root) {
        TreeNode head = new TreeNode(0);
        TreeNode pre = head;

        Deque<TreeNode> stack = new LinkedList<>();
        TreeNode p = root;
        //中序遍历
        while(p != null || !stack.isEmpty()) {
            while(p != null) {
                stack.push(p);
                p = p.left;
            }
            p = stack.pop();//中序
//构建单链表
            p.left = null;//置空左
            pre.right = p;//next
            pre = p;//后移pre

            p = p.right;//中序
        }
        return head.right;
    }
}
```

python3 双100实现
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def convertBiNode(self, root: TreeNode) -> TreeNode:
        head = TreeNode(0)
        pre = head
        stack = []
        p = root
        while stack or p:
            while p:
                stack.append(p)
                p = p.left
            p = stack.pop()
            p.left = None
            pre.right = p
            pre = p
            p = p.right
        return head.right
```

