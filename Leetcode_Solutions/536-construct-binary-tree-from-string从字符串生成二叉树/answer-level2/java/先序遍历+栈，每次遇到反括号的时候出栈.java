### 解题思路
1.二叉树的生成方式是先序遍历（其实就是深度优先），所以用个栈来存储节点。
2.每个字符不是数字或者“-”的时候，生成新的节点，入栈，如果结束字符是')'，则表示当前节点结束遍历，需要出栈。那么出栈后的栈顶节点就是当前节点的父节点（只要字符串合法，就不可能空指针）。
3.父节点左子树如果空，则赋值到左子树，否则赋值到右子树。

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
    public TreeNode str2tree(String s) {
        if (s == null ||s.length() == 0){
            return null;
        }
        // 处理根节点
        int index = s.indexOf('(');
        if (index < 0){
            return new TreeNode(Integer.valueOf(s));
        }
        // 根节点
        TreeNode root = new TreeNode(Integer.parseInt(s.substring(0,index)));
        StringBuilder prefix = new StringBuilder();
        Deque<TreeNode> stack = new LinkedList<>();// 栈
        stack.push(root);// 根节点入栈
        for (int i = index + 1; i < s.length(); i++){
            char c = s.charAt(i);
            if ((c >= '0' && c <= '9') || c == '-'){
                prefix.append(c);
            }else {
                if (prefix.length() > 0){
                    // 新元素入栈
                    stack.push(new TreeNode(Integer.parseInt(prefix.toString())));
                    prefix.setLength(0);
                }
                if (c == ')'){
                    // 反括号表示栈顶节点生成结束，没有子树了，要出栈
                    TreeNode node = stack.pop();
                    // 这里只要字符串s是合法的，就不会出现空指针
                    TreeNode parent = stack.peek();
                    if (parent.left == null){
                        parent.left = node;
                    }else {
                        parent.right = node;
                    }
                }
            }
        }
        return root;
    }
}
```