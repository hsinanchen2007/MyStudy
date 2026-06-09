```java
class Solution {
    public TreeNode constructFromPrePost(int[] pre, int[] post) {
        return construct(pre, 0, pre.length - 1, post, 0, post.length - 1);
    }

    private TreeNode construct(int[] prev, int rs, int re, int[] post, int os, int oe) {
        if (rs > re) {
            return null;
        }
        TreeNode root = new TreeNode(prev[rs]);
        if (rs < re) {
            int lr = findOe(post, os, oe - 1, prev[rs + 1]);
            int ll = lr - os + 1;
            root.left = construct(prev, rs + 1, rs + ll, post, os, lr);
            root.right = construct(prev, rs + ll + 1, re, post, lr + 1, oe - 1);
        }
        return root;
    }

    private int findOe(int[] post, int os, int oe, int val) {
        for (int i = os; i <= oe; i++) {
            if (post[i] == val) {
                return i;
            }
        }
        return -1;
    }
}
```
