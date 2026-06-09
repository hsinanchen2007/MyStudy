### 解题思路
#### 思路 1：
根据题意，模拟，不断删除叶子节点
#### 代码

```java
class Solution {
    public List<List<Integer>> findLeaves(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null) {
            return res;
        }
        while (root.left != null || root.right != null) {
            List<Integer> currentRes = new ArrayList<>();
            deleteLeaf(root, currentRes);
            res.add(currentRes);
        }
        List<Integer> rootRes = new ArrayList<>();
        rootRes.add(root.val);
        res.add(rootRes);
        return res;
    }

    private boolean deleteLeaf(TreeNode root, List<Integer> leafs) {
        if (root == null) {
            return true;
        }
        if (root.left == null && root.right == null) {
            leafs.add(root.val);
            return true;
        }
        boolean leftIfLeaf = deleteLeaf(root.left, leafs);
        boolean rightIsLeaf = deleteLeaf(root.right, leafs);
        if (leftIfLeaf) {
            root.left = null;
        }
        if (rightIsLeaf) {
            root.right = null;
        }
        return false;
    }

}
```

#### 思路二：
后序遍历：
1. 对于叶子节点来说，它的高度为 0
2. 对于非叶子节点来说，它的高度为 max(left, right) + 1
```
private int deletedLeafNode(TreeNode root, List<List<Integer>> res) {
    if (root == null) {
        return -1;
    }
    int leftLevel = deletedLeafNode(root.left, res);
    int rightLevel = deletedLeafNode(root.right, res);
    int currentLevel = Math.max(leftLevel, rightLevel) + 1;
    if (currentLevel >= res.size()) {
        res.add(currentLevel, new ArrayList<>());
    }
    res.get(currentLevel).add(root.val);
    return currentLevel;
}
```
