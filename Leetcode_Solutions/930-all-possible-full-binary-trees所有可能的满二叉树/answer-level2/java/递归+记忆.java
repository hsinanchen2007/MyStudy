```java
class Solution {
    private Map<Integer, List<TreeNode>> map = new HashMap<>();

    public List<TreeNode> allPossibleFBT(int n) {
        if (n % 2 == 0) {
            return Collections.emptyList();
        }
        if (n == 1) {
            return Collections.singletonList(new TreeNode(0));
        }
        if (map.containsKey(n)) {
            return map.get(n);
        }
        List<TreeNode> list = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            TreeNode root;
            List<TreeNode> leftList = allPossibleFBT(i);
            List<TreeNode> rightList = allPossibleFBT(n - 1 - i);
            for (TreeNode left : leftList) {
                for (TreeNode right : rightList) {
                    root = new TreeNode(0);
                    root.left = left;
                    root.right = right;
                    list.add(root);
                }
            }
        }
        map.put(n, list);
        return list;
    }

}
```
