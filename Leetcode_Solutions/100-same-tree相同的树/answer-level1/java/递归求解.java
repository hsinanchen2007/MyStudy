### 解题思路
递归求解，分以下几种情况：
* 两个指针都为空，返回true
* 一个为空，一个不为空，返回false
* 两个都不为空，则递归判断其左子树和右子树

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
        if(p==null&& q == null){
            return true;
        }
        if((p==null&&q!=null)||(p!=null && q==null)){
            return false;
        }
        if(p.val != q.val){
            return false;
        }
        if(!isSameTree(p.left,q.left)||!isSameTree(p.right,q.right)){
            return false;
        }
        return true;
    }
}
```