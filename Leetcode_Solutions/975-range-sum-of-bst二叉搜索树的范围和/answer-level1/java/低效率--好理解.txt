### 解题思路
借助了平衡二叉树的特性，先中序输出是有序的列表，然后再求和，效率比较低。

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
    List<Integer> list = new ArrayList<>();

    public int rangeSumBST(TreeNode root, int L, int R) {
        preOrderSearch(root);
        System.out.println(list.toString());
        int sum = 0;
        boolean isBegin = false;
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i) == L) {
                isBegin = true;
            } else if (list.get(i) == R) {
                sum += list.get(i);
                break;
            }
            if (isBegin) {
                sum += list.get(i);
            }
        }
        return sum;
    }

    private void preOrderSearch(TreeNode root) {
        if (root == null) {
            return;
        }
        preOrderSearch(root.left);
        list.add(root.val);
        preOrderSearch(root.right);
    }
}
```