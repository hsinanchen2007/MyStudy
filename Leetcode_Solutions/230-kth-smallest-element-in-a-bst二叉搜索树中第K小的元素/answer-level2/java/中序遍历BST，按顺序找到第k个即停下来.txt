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
    int res;
    boolean flag;
    int count;
    public int kthSmallest(TreeNode root, int k) {
        inorder(root,k);
        return res;
    }
    public void inorder(TreeNode root,int k){
        if(root!=null&&!flag){
            inorder(root.left,k);
            if(++count==k){
                flag=true;
                res=root.val;
            }
            inorder(root.right,k);
        }
    }
}
```