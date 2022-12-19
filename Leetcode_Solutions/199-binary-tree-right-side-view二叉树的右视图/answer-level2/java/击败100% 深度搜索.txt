#基本想法
可以用一个值deep记录当前从右观看到的深度 初始为-1 
从根节点开始 如果节点不为空 并且该节点的深度（由help中的参数得到深度）大于deep则可以将这个点加入 并且更新deep，继续对右子树 左子树搜索。
help()用于递归 每次向其中传入节点 以及该节点的深度
#代码
```
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
     private int deep=-1;
    List<Integer>result=new ArrayList<>();
    public List<Integer> rightSideView(TreeNode root) {
        if(root==null)return result;
        help(root,0);
        return result;
    }
    public void help(TreeNode root ,int current){
            if(root==null)return;
            if(current>deep){
            result.add(root.val);
            deep++;
            }
            help(root.right,current+1);
            help(root.left,current+1);
    }
}
```
