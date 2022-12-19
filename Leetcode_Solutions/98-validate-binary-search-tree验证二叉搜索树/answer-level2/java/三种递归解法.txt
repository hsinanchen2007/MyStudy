# 思想: BST中序遍历是有序的
### 方法1. 先存储再比较
```
class Solution {
    public boolean isValidBST(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        inOrderTravel(root, list);        
        for (int i = 1; i < list.size(); ++i) if (list.get(i) <= list.get(i - 1)) return false;
        return true;
    }
    private void inOrderTravel(TreeNode root, List list) {
        if (root == null) return;
        inOrderTravel(root.left, list);
        list.add(root.val);
        inOrderTravel(root.right, list);
    }
}
```
时间复杂度: O(n)
空间复杂度: O(n)

### 方法2. 一边递归一边比较
```
class Solution {
    private long prev = Long.MIN_VALUE;
    public boolean isValidBST(TreeNode root) {
        if (root == null) return true;
        return isValidBST(root.left) && prev < (prev = root.val) && isValidBST(root.right);
    }
}
```
时间复杂度: O(n)
空间复杂度: O(h)

### 方法3. 范围检查

```
class Solution {
    public boolean isValidBST(TreeNode root) {
        if (root == null) return true;
        return isValidBSTHelper(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
    private boolean isValidBSTHelper(TreeNode root, long left, long right) {
        if (root == null) return true;
        if (root.val <= left  || root.val >= right) return false;
        return isValidBSTHelper(root.left, left, root.val) && 
            isValidBSTHelper(root.right, root.val, right);
    }
}
```
时间复杂度: O(n)
空间复杂度: O(h)

