### 解题思路
此处撰写解题思路

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

    private int closestValue(List<Integer> list, double target) {
        int i = 0, j = list.size() - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (list.get(mid) < target) i = mid + 1;
            else j = mid - 1;
        }

        if (i >= list.size()) return list.get(j);
        if (j < 0) return list.get(i);

        return (Math.abs(list.get(i) - target) < Math.abs(list.get(j) - target))
                ? list.get(i) : list.get(j);
    }

    private void inorder(TreeNode node, List<Integer> list) {
        if (node != null) {
            inorder(node.left, list);
            list.add(node.val);
            inorder(node.right, list);
        }
    }

    public int closestValue(TreeNode root, double target) {
        List<Integer> list = new ArrayList<>();
        inorder(root, list);

        return closestValue(list, target);
    }
}
```