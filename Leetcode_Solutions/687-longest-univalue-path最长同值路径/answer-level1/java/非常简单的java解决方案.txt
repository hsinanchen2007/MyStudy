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
    int max=0;
    public int longestUnivaluePath(TreeNode root) {
            int longestdigui = longestdigui(root);
        if(longestdigui==-1) return 0;
        return max;
    }
       public  int longestdigui(TreeNode root){
    if (root == null) {
            return -1;
        }
        int res=0;
        int left = longestdigui(root.left);
        int right = longestdigui(root.right);
        if (left != -1 && right != -1) {
            if(root.val==root.left.val&&root.val==root.right.val){
                max=Math.max(max,left+right);
                res=Math.max(left,right)+1;
            }
            else if(root.val==root.left.val) res+=left+1;
            else if(root.val==root.right.val) res+=right+1;
            else res=0;
        }
        else  if (left==-1&&right==-1) return 1;
        else if (left != -1) {
            if(root.val==root.left.val) res+=left+1;
        } else if (right != -1) {
            if(root.val==root.right.val) res+=right+1;
        }
        max=Math.max(max,res-1);
        if(res==0) return 1;
        return res;
    }
}
```
直接往下递归就行了，然后回来的时候返回值，这时候父节点要去检测他的子节点是否与他相等，如果都不想等，那么直接向上返回1，就行了。