### 解题思路
此前的思路是找到第一个点的所有祖先，然后在此遍历树，将第一个点的祖先与第二个点的祖先匹配，
后面发现只需找到所有点的祖先，然后根据这两个点的最近祖先以前的公共祖先相同，所以只要找到不同的祖先
则这个祖先前一个祖先一定是最近祖先

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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        List<TreeNode> pList=new ArrayList<>();
        List<TreeNode> qList=new ArrayList<>();
        findNode(root, p, pList);
        findNode(root, q, qList);
        int minSize = Math.min(pList.size(),qList.size());
        for(int i=0;i<minSize;i++){
            if(pList.get(i).val!=qList.get(i).val){
                return pList.get(i-1);
            }
        }
        return pList.get(minSize-1);
    }
    public void findNode(TreeNode root, TreeNode node, List<TreeNode> list){
        if (root == null) {
            return;
        }
        list.add(root);
        if (root.val == node.val) {
            return;
        } else if(root.val < node.val) {
            findNode(root.right, node, list);
            return;
        } else if(root.val > node.val){
            findNode(root.left, node, list);
            return;
        }
    }
}
```