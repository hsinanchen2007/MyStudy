### 解题思路
1 思路 求出树的最大高度
2 将每个节点高度 和最大高度求差。 
3 差如果大于1 的话，就返回负数。
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
       if(root == null){
           return true;
       }
       if(checkNodeHigh(root)>-1){
           return true;
       }
       return false;
 
    }
    public int  checkNodeHigh(TreeNode node){
          if(node == null){
              return 0;
          }

          int a= checkNodeHigh(node.left);
          int b= checkNodeHigh(node.right);
          if(a<0||b<0){
              return -1;
          }
          
          if(Math.abs(a-b)>1){
              return -1;
          }
        return   Math.max(a,b)+1;
    }
}
```