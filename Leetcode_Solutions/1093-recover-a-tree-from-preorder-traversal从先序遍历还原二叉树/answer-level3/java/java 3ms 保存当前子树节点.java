按照先序遍历法，规则：深度递增或相等说明在同一颗子树上面，一旦深度减小说明在某个父节点上产生了新的右子树；
```
public class RecoverFromPreorder {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }
    int curIndex = 0;
    int curValue = 0;
    int curDepth = 0;
    int lastDepth = 0;

    public TreeNode recoverFromPreorder(String S) {
        TreeNode root = null;
        char[] chars = S.toCharArray();
        TreeNode lastParent = null;
        TreeNode lastNode = null;
        while (parseNextDepthAndValue(chars)) {
            if (root == null) {
                root = new TreeNode(curValue);
                lastNode = root;
                continue;
            }
            TreeNode parent = root;
            if (curDepth > lastDepth) {
                // 深度递增，说明是上一个节点的子节点
                parent = lastNode;
            } else if (curDepth == lastDepth) {
                // 深度相等，说明是兄弟节点
                parent = lastParent;
            } else {
                // 深度减小，说明产生了新的右子树，从根节点向右回溯
                int len = curDepth;
                while (--len != 0) {
                    parent = parent.right != null ? parent.right : parent.left;
                }
            }
            lastParent = parent;
            lastNode = new TreeNode(curValue);
            if (parent.left == null) {
                parent.left = lastNode;
            } else {
                parent.right = lastNode;
            }
        }
        return root;
    }

    private boolean parseNextDepthAndValue(char[] chars) {
        if (curIndex == chars.length) {
            return false;
        }
        lastDepth = curDepth;
        curDepth = 0;
        while (chars[curIndex] == '-') {
            curDepth++;
            curIndex++;
        }
        StringBuilder sb = new StringBuilder();
        while (curIndex < chars.length && chars[curIndex] != '-') {
            sb.append(chars[curIndex]);
            curIndex++;
        }
        curValue = Integer.parseInt(sb.toString());
        return true;
    }
}
```
