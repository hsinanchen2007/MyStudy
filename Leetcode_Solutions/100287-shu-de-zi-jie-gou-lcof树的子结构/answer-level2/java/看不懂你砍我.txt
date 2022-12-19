看不懂你砍我

```
public boolean isSubStructure(TreeNode A, TreeNode B) {
        if (A == null || B == null) {
            return false;
        }
        boolean res = true;
        Stack<TreeNode> stack = new Stack<>();
        stack.add(A);

        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            //当当前节点等于B树的根节点时，就判断
            if (node.val == B.val && same(node, B)){
                return true;
            } else {
                if (node.left != null) {
                    stack.add(node.left);
                }
                if (node.right != null) {
                    stack.add(node.right);
                }
            }
        }
        return false;
    }

    public boolean same(TreeNode A, TreeNode B) {
        if (A == null) {
            return false;
        }
        boolean a = true;
        boolean b = true;
        if (A.val == B.val) {
            if (B.left != null) {
                a = same(A.left, B.left);
            }
            if (B.right != null) {
                b = same(A.right, B.right);
            }
        }else {
            return false;
        }
        return a && b;
    }
```
