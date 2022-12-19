### 解题思路
每到一个新的节点都进行检测，是否符合二叉搜索树的规定，若不符合，则直接返回false.

### 代码

```java
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
    public boolean isValidBST(TreeNode root) {
        // 对于根节点为空，当然返回正确
        if(root == null)
            return true;

        // 否则从根节点开始进行深度优先搜索
        return depthFirstSearch(new Stack<>(), root);
    }

    // stack从栈底到栈顶存储着从根节点到node的父节点的路径（包括端点），并且还存储了“L”或“R”，用于指示下一个子节点是左孩子还是右孩子
    public boolean depthFirstSearch(Stack<Pair<TreeNode, String>> stack, TreeNode node){
        TreeNode left = node.left;
        TreeNode right = node.right;

        // 栈空，节点无子节点，说明只有一个根而已，返回正确！
        if(stack.empty() && left == null && right == null)
            return true;
        
        // 创建一个oldStack, 是为了检查node的值是否符合二叉搜索树的规定
        Stack<Pair<TreeNode, String>> oldStack = new Stack<>();
        oldStack.addAll(stack);
        
        // 只有栈非空才有检索的必要
        if(!stack.empty()){
            // childVal 的值是固定的，我们只需要用childVal和其（祖）父节点根据左、右方向进行对比，因为能来到这一层，说明上面的路径都是符合二叉搜索树规定的，这是我们的假设
            int childVal = node.val;
            // 从栈顶拿出一个元素
            Pair<TreeNode, String> poped = oldStack.pop();
            // 给parentVal赋值
            int parentVal = poped.getKey().val;
            // direction 指示的是node在其（祖）父节点的左边("L")还是右边("R")
            String direction = poped.getValue();
            switch (direction){
            // 根据左右不同，分别对应错误情况返回false
                case "L":
                    if(childVal >= parentVal)
                        return false;
                    break;
                case "R":
                    if(childVal <= parentVal)
                        return false;
                    break;
            }
            // 循环中的情况类似的
            while(!oldStack.empty()){
                poped = oldStack.pop();
                direction = poped.getValue();
                parentVal = poped.getKey().val;
                switch (direction) {
                    case "L":
                        if (childVal >= parentVal)
                            return false;
                        break;
                    case "R":
                        if (childVal <= parentVal)
                            return false;
                        break;
                }
            }
        }

        // 能来到这里，说明node的val值符合二叉搜索树的规定，我们可以检查其左右子节点的值是否符合规定了
        if(node.left != null || node.right != null){
            boolean leftValid = true;
            boolean rightValid = true;
            if(node.left != null){
                Stack<Pair<TreeNode, String>> stackLeft = new Stack<>();
                stackLeft.addAll(stack);
                stackLeft.add(new Pair(node, "L"));
                leftValid = depthFirstSearch(stackLeft, node.left);
            }
            if(node.right != null){
                Stack<Pair<TreeNode, String>> stackRight = new Stack<>();
                stackRight.addAll(stack);
                stackRight.add(new Pair(node, "R"));
                rightValid = depthFirstSearch(stackRight, node.right);
            }

            // 能来到这一步，说明 node 的val值符合二叉搜索树的规定, 且没有左右子节点，故而返回正确！
            return leftValid && rightValid;
        }
        
        return true;
    }
}
```