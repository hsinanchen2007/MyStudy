执行用时 :0 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :34.2 MB, 在所有 Java 提交中击败了39.38%的用户

个人感觉：感觉官方给的题解有的不能执行（小白一只，如果说错了请指出）
    例如{1,2,3,4,5,null,null,7,8,null,null,null,null}


public TreeNode invertTree(TreeNode root) {
        if(root == null) return root;
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;
        invertTree(root.right);
        invertTree(root.left);
        return root;
    }

