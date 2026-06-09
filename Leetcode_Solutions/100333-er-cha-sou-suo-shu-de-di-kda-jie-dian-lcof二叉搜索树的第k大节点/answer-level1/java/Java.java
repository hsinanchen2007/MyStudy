### 解题思路
递归纠结了很久原因是判断root非空的if写成了while，还是没有理解递归。while应该是栈的写法。

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
    int count = 0;
    int result = -1;
    public int kthLargest(TreeNode root, int k) {
        inorder(root,k);
        return result;
    }

    public void inorder(TreeNode root, int k){
        if(root==null){
            return;
        }
        if(root!=null){
            inorder(root.right,k);
            count++;
            if(count==k){
                result = root.val;
                count++;
                return;
            }
            inorder(root.left,k);
        }
    }
}
```