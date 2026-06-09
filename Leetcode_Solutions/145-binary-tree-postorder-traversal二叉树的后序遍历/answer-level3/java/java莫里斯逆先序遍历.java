### 解题思路
将先序的莫里斯改写，left和right颠倒，变成访问根节点后，先访问右节点，再访问左节点，通过头插法，逆序访问结果序列，然后返回

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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new LinkedList<>();
        TreeNode curr = root;
        while(curr != null){
            if(curr.right == null){
                res.add(0, curr.val);
                curr = curr.left;
            }else{
                TreeNode pre = curr.right;
                while(pre.left != null && pre.left != curr)
                    pre = pre.left;
                if(pre.left == null){
                    res.add(0, curr.val);
                    pre.left = curr;
                    curr = curr.right;

                }else{
                    pre.left = null;
                    curr = curr.left;
                }
            }
        }
        return res;
    }
}
```