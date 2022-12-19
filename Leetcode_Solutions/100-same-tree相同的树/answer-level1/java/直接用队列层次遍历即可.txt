```
 public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p==null && q==null)
            return true;
        else if (p==null||q==null)
            return false;

        Queue<TreeNode> s1 = new LinkedList<>();
        Queue<TreeNode> s2 = new LinkedList<>();

        s1.add(p);
        s2.add(q);
        while (!s1.isEmpty() && !s2.isEmpty()){
            TreeNode n1 = s1.poll();
            TreeNode n2 = s2.poll();

            if (n1==null && n2==null)
                continue;
            else if (n1==null||n2==null)
                return false;

            if (n1.val!=n2.val)
                return false;
            s1.add(n1.left);
            s1.add(n1.right);
            s2.add(n2.left);
            s2.add(n2.right);

        }

        if (!s1.isEmpty()||!s2.isEmpty())
            return false;
        return true;
    }
```
