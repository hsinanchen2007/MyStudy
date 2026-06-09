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
    public List<TreeNode> allPossibleFBT(int N) {
        List<TreeNode> ans=new ArrayList<>();
        if(N%2==0)
            return ans;  //无法构成二叉树
        if(N==1)
        {
            TreeNode head=new TreeNode(0);
            ans.add(head);
            return ans;
        }
        for(int i=1;i<N;i++){
            List <TreeNode> left=allPossibleFBT(i);
            List <TreeNode> right=allPossibleFBT(N-i-1);
            for(TreeNode l:left){
                for(TreeNode r:right){
                    TreeNode head=new TreeNode(0);
                    head.left=l;
                    head.right=r;
                    ans.add(head);
                }
            }
        }
        return ans;

    }
}
```