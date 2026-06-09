### 解题思路
先序遍历二叉树 剪枝条件：如果两个子节点都是null返回true 一个null 一个非null 返回false 值val不相等返回false 

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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p==null&&q==null){
            return true;
        }
        if((p==null&&q!=null)||(p!=null&&q==null)){
            return false;
        }
        if(p.val!=q.val){
            return false;
        }
        if(!(isSameTree(p.left, q.left))){
            return false;
        }
        if(!(isSameTree(p.right, q.right))){
            return false;
        }
        return true;
    }
}
```