```
 public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
    List<Integer> resultList = new ArrayList<Integer>();
    Stack<TreeNode> s1 = new Stack<TreeNode>();
    Stack<TreeNode> s2 = new Stack<TreeNode>();
    TreeNode c1 = root1, c2 = root2;
    boolean valid1 = true, valid2 = true;
    while (c1 != null || !s1.isEmpty() || c2 != null || !s2.isEmpty()) {
        while (valid1 && c1 != null) {
            s1.push(c1);
            c1 = c1.left;
        }
        while (valid2 && c2 != null) {
            s2.push(c2);
            c2 = c2.left;
        }
        if (valid1 && !s1.isEmpty()) {
            c1 = s1.pop();
        }         
        if (valid2 && !s2.isEmpty()) {
            c2 = s2.pop();
        }
        if (c1 == null) {
            resultList.add(c2.val);
            c2 = c2.right;
            valid1 = false;
            valid2 = true;
        }
        else if (c2 == null) {
            resultList.add(c1.val);
            c1 = c1.right;
            valid1 = true;
            valid2 = false;
        }
        else if (c1.val <= c2.val) {
            resultList.add(c1.val);
            c1 = c1.right;
            valid2 = false;
            valid1 = true;
        }
        else {
            resultList.add(c2.val);
            c2 = c2.right;
            valid2 = true;
            valid1 = false;
        }
    }
    return resultList;
}
```
