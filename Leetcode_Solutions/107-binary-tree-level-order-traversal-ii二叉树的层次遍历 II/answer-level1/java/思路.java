### 解题思路
此处撰写解题思路
正序层次遍历后将结果倒序。
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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        if(root ==null) {
            return new ArrayList<>();
        }
        int level = 0;
        ret = levelOrderBottomMethod(root, level, ret);
        List<List<Integer>> ret1 = new ArrayList<List<Integer>>();
        if (ret.size() > 0) {
            for(int i = ret.size()-1; i>=0; i--) {
                ret1.add(ret.get(i));
            }
        }
        
        return ret1;
    }
 
    public List<List<Integer>> levelOrderBottomMethod(TreeNode root, int level, List<List<Integer>> ret) {
        if (level == ret.size()) {
            ret.add(new ArrayList<Integer>());
        }
        if (root != null){
            ret.get(level).add(root.val);
            if (root.left != null) {
                levelOrderBottomMethod(root.left, level+1, ret);
            }
            if (root.right != null) {
                levelOrderBottomMethod(root.right, level+1, ret);
            }
        }
        
        return ret;
    }
}
