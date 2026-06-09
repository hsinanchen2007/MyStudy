使用两个辅助栈，如果当前打印的是奇数层，先保存做左子节点再保存右子节点到第一个栈里；如果当前打印的是偶数层，则先保存右子节点再保存左子节点到第二个栈里。
 ```
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

class Solution {

    public List<List<Integer>> levelOrder(TreeNode root) {

        if (root == null) {
            return new ArrayList<>();
        }
        List<List<Integer>> result = new ArrayList<>();
        Stack<TreeNode> stack1 = new Stack<>();//存放奇数层的节点
        Stack<TreeNode> stack2 = new Stack<>();//存放偶数层的节点
        stack1.push(root);

        int count = 0;
        while (!stack1.isEmpty() || !stack2.isEmpty()) {
            List<Integer> list = new ArrayList<>();
            count++;
            if ((count & 1) == 1) {
                while (!stack1.isEmpty())      //清空stack1时，依次将栈顶节点子节点（先左后右）压入stack2
                {
                    TreeNode pop = stack1.pop();
                    list.add(pop.val);
                    if (pop.left != null) stack2.push(pop.left);
                    if (pop.right != null) stack2.push(pop.right);
                }
            } else {
                while (!stack2.isEmpty())       //清空stack2时，依次将栈顶节点子节点（先右后左）压入stack1
                {
                    TreeNode top = stack2.pop();
                    list.add(top.val);
                    if (top.right != null) stack1.push(top.right);
                    if (top.left != null) stack1.push(top.left);
                }
            }
            result.add(list);
        }
        return result;

    }

}

```
