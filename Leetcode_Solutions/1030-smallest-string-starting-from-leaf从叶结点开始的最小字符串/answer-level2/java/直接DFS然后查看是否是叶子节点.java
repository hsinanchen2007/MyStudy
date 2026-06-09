### 解题思路
就是DFS遍历。。。写的有点啰嗦

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
    private ArrayList<Integer> ans = new ArrayList<>();
    public String smallestFromLeaf(TreeNode root) {
        if(root==null)
            return "";
        if(root.left==null && root.right==null)
            return (char)(root.val+97)+"";
        dfs(root, new ArrayList<Integer>());
        return convertNum2String(ans);

    }

    private String convertNum2String(ArrayList<Integer> ans) {
        StringBuilder builder = new StringBuilder();
        for(Integer i : ans)
            builder.append((char)(i+97));
        return builder.toString();
    }

    private void dfs(TreeNode root, ArrayList<Integer> builder) {
        if(root==null)
            return;
        builder.add(0, root.val);
        if(root.left==null && root.right==null){
            ans = (ArrayList<Integer>) sortAns(builder).clone();
        }
        if(root.left!=null){
            dfs(root.left, builder);
        }
        if(root.right!=null){
            dfs(root.right, builder);
        }
        if(builder.size()>0)
            builder.remove(0);
    }

    private ArrayList<Integer> sortAns(ArrayList<Integer> builder) {
        if(ans==null || ans.size()==0)
            return builder;
        int length = ans.size()>builder.size()?ans.size():builder.size();
        for(int i=0; i<length; i++){
            if(i >= ans.size())
                return ans;
            if(i >= builder.size())
                return builder;
            if(ans.get(i) > builder.get(i))
                return builder;
            else if(ans.get(i) < builder.get(i))
                return ans;
        }
        return ans;
    }
}
```