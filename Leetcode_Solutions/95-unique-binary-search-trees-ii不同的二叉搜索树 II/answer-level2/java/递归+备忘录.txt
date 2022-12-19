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
    public List<TreeNode> generateTrees(int n) {
        if(n<=0){
            return new ArrayList();
        }
        List<TreeNode>[][] dp = new ArrayList[n+1][n+1];
        return _generateTrees(1,n,dp);
    }

    private List<TreeNode> _generateTrees(int start,int end,List<TreeNode>[][] dp){
        if(dp[start][end]!=null){
            return dp[start][end];
        }
        List<TreeNode> ans = new ArrayList<>();
        if(start==end){
            ans.add(new TreeNode(start));
            dp[start][end]=ans;
            return ans;
        }

        for(int i=start;i<=end;i++){
            List<TreeNode> leftList=null;
            List<TreeNode> rightList = null;
            List<TreeNode> list = new ArrayList<>();

            if(i>start){
               leftList = _generateTrees(start, i - 1, dp);
            }

            if(i<end){
                rightList = _generateTrees(i+1,end,dp);
            }

            if(i==start){
               for(TreeNode node:rightList){
                   TreeNode head=new TreeNode(i);
                   head.right=node;
                   ans.add(head);
               }
            }else if(i==end){
                for(TreeNode node:leftList){
                    TreeNode head=new TreeNode(i);
                    head.left=node;
                    ans.add(head);
                }
            }else{
                for(TreeNode left:leftList){
                    for(TreeNode right:rightList){
                        TreeNode head=new TreeNode(i);
                        head.left= left;
                        head.right=right;
                        ans.add(head);
                    }
                }
            }
        }
        dp[start][end]=ans;
        return ans;
    }
}
```