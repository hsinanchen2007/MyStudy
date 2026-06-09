![image.png](https://pic.leetcode-cn.com/45cfce368fd114ebb8bb7be0dda2a571f0d70ddea6a5429e80fa1c893fa0437f-image.png)
```
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
    static List<Integer> list = new ArrayList<>();
    static List<Integer> result = new ArrayList<>();
    public int[] findMode(TreeNode root) {
        if (root == null) {
            return new int[0];
        }
        if (root.left == null && root.right == null) {
            return new int[]{root.val};
        }
        getToList(root);
        int size = list.size();
        int mid = list.size() / 2;
        if (size % 2 == 0) {

            if (list.get(0) == list.get(mid - 1) && list.get(mid) == list.get(list.size() - 1)) {
                   return new int[]{list.get(0),list.get(list.size() - 1)};
            } else if (list.get(0) == list.get(mid - 1)) {
                  return new int[]{list.get(0)};
            } else if (list.get(mid) == list.get(list.size() - 1)) {
                return new int[]{list.get(list.size() - 1)};
            } else {
                 return new int[]{list.get(mid - 1)};
            }

        } else {
            return  new int[]{list.get(mid)};

        }
    }
    // 中序遍历先拿到升序数组
     public void getToList(TreeNode root) {
        if ((root != null)) {
            getToList(root.left);
           list.add(root.val);
           getToList(root.right);
        }
    }
}
```
