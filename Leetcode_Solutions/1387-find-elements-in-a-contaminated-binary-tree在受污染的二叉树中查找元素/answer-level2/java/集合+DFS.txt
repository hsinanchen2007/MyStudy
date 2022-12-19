```java
class FindElements {
    private Set<Integer> set;

    public FindElements(TreeNode root) {
        set = new HashSet<>();
        recover(root, 0);
    }
    
    private void recover(TreeNode root, int pVal) {
        if (root == null) {
            return;
        }
        set.add(pVal);
        pVal <<= 1;
        recover(root.left, 1 + pVal);
        recover(root.right, 2 + pVal);
    }


    public boolean find(int target) {
        return set.contains(target);
    }
}
```
