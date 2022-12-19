### 解题思路
执行用时 :
1 ms
, 在所有 java 提交中击败了
64.57%
的用户
内存消耗 :
37.6 MB
, 在所有 java 提交中击败了
52.28%
的用户

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
    boolean b=false;
    public boolean hasPathSum(TreeNode root, int sum) {
        recursive_tree(root,0,sum);
        return b;
    }
    public void recursive_tree(TreeNode root,int s,int target){
        
        if(root==null){
            return;
        }
        s+=root.val;
        if(root.left==null&&root.right==null){//叶子节点
            if(s==target) {
                b = true;
                return;
            }else {
                return;
            }
        }
        recursive_tree(root.left,s,target);
        recursive_tree(root.right,s,target);
    }
}
```