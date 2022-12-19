### 解题思路
此处撰写解题思路
简单dfs
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

    int limit;

    public TreeNode sufficientSubset(TreeNode root, int limit) {
        if(root == null)return null;
        this.limit = limit;
        return dfs(root, 0)?root:null;
    }

    boolean dfs(TreeNode node, int sum){//true表示保留该结点，false表示删除该结点。
        if(node != null){
            if(node.left == null && node.right == null){//判断是否为叶子节点，如果是那么判断根-叶的和是否小于limit
                if(node.val + sum < limit){
                    return false;//删除该结点，返回父节点处
                }
                return true;//保留该结点
            }
            boolean res1 = dfs(node.left, sum + node.val);
            boolean res2 = dfs(node.right, sum + node.val);
            if(!res1){
                node.left = null;//删除左结点
            }
            if(!res2){
                node.right = null;//删除右结点
            }
            return res1 || res2;//如果存在一个true，那么此结点就不能删
        }  
        return false;  
    }

}
```