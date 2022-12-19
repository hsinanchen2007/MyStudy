### 解题思路
执行用时 :
0 ms
, 在所有 java 提交中击败了
100.00%
的用户
内存消耗 :
37.9 MB
, 在所有 java 提交中击败了
37.54%
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
    public int maxdepth=0;
    public int maxDepth(TreeNode root) {
        recursive_tree(root,0);
        return maxdepth;
    }
    public void recursive_tree(TreeNode root,int depth){
        if(root==null){
            return;
        }
        if(root.left==null&&root.right==null){
            depth++;
            if(depth>maxdepth){
                maxdepth=depth;
            }
            return;
        }
        depth++;
        recursive_tree(root.left,depth);
        recursive_tree(root.right,depth);

    }
}
```