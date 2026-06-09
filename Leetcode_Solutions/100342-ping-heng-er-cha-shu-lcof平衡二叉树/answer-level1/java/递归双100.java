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
    public boolean isBalanced(TreeNode root) {
        // 递归: root平衡条件时 left平衡且right平衡且left高度与right高度差不超过1。
        // 栈+宽度遍历+map存放<node，高度>
        if(root==null) return true;
        int R= getHeight(root.right);
        int L= getHeight(root.left);
        if( L!=-1 && R!=-1 && Math.abs(L-R)<=1 ){
            return true;
        }
        return false;
    }
    //返回树的高度，若树为不平衡，直接返回-1
    int getHeight(TreeNode node){
        if( node==null ) return 0;
        int R= getHeight(node.right);
        int L= getHeight(node.left);
        if( L==-1 || R==-1 || Math.abs(L-R)>1 ){
            return -1;
        }
        return Math.max(L,R)+1;
    }
}
```