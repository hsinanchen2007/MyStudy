执行结果：
通过
显示详情
执行用时 :
8 ms
, 在所有 Java 提交中击败了
94.63%
的用户
内存消耗 :
36.5 MB
, 在所有 Java 提交中击败了
98.80%
的用户
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
    List<TreeNode> list = new ArrayList<>();
    public void recoverTree(TreeNode root) {
        pro(root);
        for(int i=list.size()-1; i>0;i--){
            TreeNode tn = list.get(i);
            for(int j=i-1;j>=0;j--){
                TreeNode t3 = list.get(j);
                if(t3.val>tn.val&&(j-1<0||j-1>=0&&list.get(j-1).val<tn.val)){
                    int temp = t3.val;
                    t3.val=tn.val;
                    tn.val=temp;
                    return;
                }
            }
        }
    }
    public void pro(TreeNode node){
        if(node==null)return;
        pro(node.left);
        // System.out.println(node.val);
        list.add(node);
        pro(node.right);
    }
}
```
