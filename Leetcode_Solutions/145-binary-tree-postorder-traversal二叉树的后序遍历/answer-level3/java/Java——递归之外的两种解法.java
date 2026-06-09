- 方法一 跟官方的思路差不多，但是这里用两个栈模拟，看起来更清晰
- 方法二 相当于模拟后序遍历的过程

```

class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        // 方法一：两个栈
        /*if(root != null) {
            // 左-右的形式入栈 s1，从 s1 出栈的顺序根-右-左，入栈到 s2 时，就变成了 左-右-根
            Stack<TreeNode> s1 = new Stack<>(); 
            Stack<Integer> s2 = new Stack<>();
            s1.push(root);
            while(!s1.empty()) {
                TreeNode cur = s1.pop();
                s2.push(cur.val);
                if(cur.left != null) {
                    s1.push(cur.left);
                }
                if(cur.right != null) {
                    s1.push(cur.right);
                }
            }
            while(!s2.empty()) {
                res.add(s2.pop());
            }
        }*/
        // 方法二：一个栈，加几个变量
        if(root != null) {
            Stack<TreeNode> s1 = new Stack<>();
            TreeNode c = null;  // 当前栈顶节点
            TreeNode h = root;  // 当前已出栈的节点
            s1.push(root);
            while(!s1.empty()) {
                c = s1.peek();
                // 为什么 h 既要不等于 left 也要不等于 right，考虑从右边节点返回的情况
                if(c.left != null && h != c.left && h != c.right) {
                    s1.push(c.left);
                } else if(c.right != null && h != c.right) {
                    s1.push(c.right);
                } else {
                    h = s1.pop();
                    res.add(h.val);
                }
            }
        }

        return res;
    }
}
```
