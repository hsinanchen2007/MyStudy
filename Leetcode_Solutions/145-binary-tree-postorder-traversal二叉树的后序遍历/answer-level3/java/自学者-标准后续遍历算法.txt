自后向前追溯曾经访问过的路径，就叫做回溯。
要想实现回溯，可以利用栈的先入后出特性，
也可以采用递归的方式（因为递归本身就是基于方法调用栈来实现）。
官方题解采用了堆栈方式实现，而我采用了教科书的递归实现方式实现。

### 解题思路
* 递归是利用函数堆栈特性实现的dfs深度优先遍历


### 代码

```java []
// 教科书递归版本
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        postorder(root,ans);
        return ans;
    }
    private void postorder(TreeNode root, List<Integer> ans) {
        if(root == null) {
            return;
        }
        postorder(root.left,ans);
        postorder(root.right,ans);
        ans.add(root.val);
    }
}
```
```java []
// 官方算法改进版本
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
            Stack<TreeNode> stack = new Stack<>();
            LinkedList<Integer> output = new LinkedList<>();
            if (root == null) {
                return output;
            }

            stack.push(root);
            while (!stack.isEmpty()) {
                TreeNode node = stack.pop();
                output.addFirst(node.val);
                if (node.left != null) {
                    stack.push(node.left);
                }
                if (node.right != null) {
                    stack.push(node.right);
                }
            }
            return output;
    }
    
}

```