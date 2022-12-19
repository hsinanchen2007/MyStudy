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
    public HashMap<Integer,TreeNode> map=new HashMap<>();
    public List<Integer> rightSideView(TreeNode root) {
        dfs(root,0);
        List<Integer> result=new ArrayList<Integer>();
        int hight=hight(root);
        for(int i =0;i<hight;i++){
            result.add(map.get(i).val);
        }
        return result;
    }
    public void dfs(TreeNode root,int level){
        if(root==null){
            return;
        }
        if(!this.map.containsKey(level)){
            this.map.put(level,root);
        }
        dfs(root.right,level+1);
        dfs(root.left,level+1);
    }
    public static int hight(TreeNode root){
        if(root==null){
            return 0;
        }
        int left=hight(root.left);
        int right=hight(root.right);
        return Math.max(left,right)+1;
    }
}
```