### 解题思路
简单总结就是先把BST进行中序遍历得到有序数组，再根据有序数组重新建立平衡二叉搜索树。
比赛期间遇到了一个主要的问题就是Java中的list转为int数组的过程总是报错，导致没能提交成功。后来百度参考了list与int和Integer数组间的互相转化写出了答案，看来以后还是应该尽量多掌握几门语言啊...

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode balanceBST(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        inorderBST(root, list);
        int[] nums = list.stream().mapToInt(Integer::valueOf).toArray();
        return rebuildBST(nums, 0, nums.length - 1);
    }
    public void inorderBST(TreeNode root, List<Integer> list) {
        if (root == null) {
            return;
        }
        inorderBST(root.left, list);
        list.add(root.val);
        inorderBST(root.right, list);
    }
    public TreeNode rebuildBST (int[] nums, int l, int r) {
        if (l > r) {
            return null;
        }
        int mid = (l + r) / 2;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = rebuildBST(nums, l, mid - 1);
        root.right = rebuildBST(nums, mid + 1, r);
        return root;
    }
}
```