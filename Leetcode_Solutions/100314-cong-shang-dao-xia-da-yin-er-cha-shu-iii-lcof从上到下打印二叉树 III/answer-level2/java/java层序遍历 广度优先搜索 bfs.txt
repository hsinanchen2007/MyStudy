![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/18cd30e505066c2ed0bbd2b9093a38af357797e40162dc07ff2325dbea7e0863-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)

### 解题思路
用两个栈实现层序遍历。

### 代码

```java
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null) return res;
        Stack<TreeNode> stack1 = new Stack<>();
        Stack<TreeNode> stack2 = new Stack<>();
        stack1.push(root);
        int count = 1;
        while (!stack1.isEmpty() || !stack2.isEmpty()) {
            ArrayList<Integer> list = new ArrayList<>();
            if (count % 2 == 1) {//取出来，先存左儿子，再存右儿子
                while (!stack1.isEmpty()) {
                    TreeNode tmp = stack1.pop();
                    list.add(tmp.val);
                    if (tmp.left != null) stack2.push(tmp.left);
                    if (tmp.right != null) stack2.push(tmp.right);
                }
            } else {//取出来，先存右儿子，再存左儿子
                while (!stack2.isEmpty()) {
                    TreeNode tmp = stack2.pop();
                    list.add(tmp.val);
                    if (tmp.right != null) stack1.push(tmp.right);
                    if (tmp.left != null) stack1.push(tmp.left);
                }
            }
            count++;
            res.add(list);
        }
        return res;
    }
}
```