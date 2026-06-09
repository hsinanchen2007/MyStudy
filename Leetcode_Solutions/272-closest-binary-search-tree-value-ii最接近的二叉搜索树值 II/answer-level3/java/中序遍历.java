### 解题思路
中序遍历，维持k个元素，新元素如果更接近target则选入，踢出已选元素的第一个即可

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
    LinkedList<Integer> res = new LinkedList<>();
    public List<Integer> closestKValues(TreeNode root, double target, int k) {
        if (root == null) {
            return res;
        }
        closestKValues(root.left, target, k);
        if (k > res.size()) {
            res.add(root.val);
        } else {
            if (Math.abs(target - root.val) < Math.abs(target - res.peekFirst())) {
                res.pollFirst();
                res.add(root.val);
            } else {
                return res;
            }
        }
        closestKValues(root.right, target, k);
        return res;
    }
}
```