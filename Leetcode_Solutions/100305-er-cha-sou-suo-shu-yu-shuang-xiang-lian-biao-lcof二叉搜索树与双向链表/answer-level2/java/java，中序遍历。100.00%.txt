```
    class Solution {
        public Node treeToDoublyList(Node root) {
            if (root == null) {
                return null;
            }
            
            Node[] roots = dfs(root);
            roots[0].left = roots[1];
            roots[1].right = roots[0];
            
            return roots[0];
        }

        //  每次都返回子树的 头尾 两个节点，拼接： 左子树的尾巴 - 当前节点 - 右子树的头
        private Node[] dfs(Node root) {
            if (root == null) {
                return null;
            }

            Node[] left = dfs(root.left);
            Node[] right = dfs(root.right);

            Node[] res = new Node[]{root, root};
            if (left != null) {
                left[1].right = root;
                root.left = left[1];
                res[0] = left[0];
            }

            if (right != null) {
                right[0].left = root;
                root.right = right[0];
                res[1] = right[1];
            }

            return res;
        }

    }
```
