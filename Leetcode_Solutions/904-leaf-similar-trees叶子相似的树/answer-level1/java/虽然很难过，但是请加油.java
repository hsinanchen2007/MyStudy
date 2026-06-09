### 解题思路
执行用时 :
1 ms
, 在所有 Java 提交中击败了
73.49%
的用户
内存消耗 :
34.3 MB
, 在所有 Java 提交中击败了
91.84%
的用户
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
    public ArrayList<Integer> tree_leaf=new ArrayList<>();
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        if(isleaf(root1)==true&&isleaf(root2)==true){//都是只有一个节点
           if(root1.val==root2.val) {
               return true;
           }else{
               return false;
           }
           //多个节点的情况下递归
        }
        recursive_middle_order(root1);
        recursive_middle_order(root2);
        if(tree_leaf.size()%2!=0)
        {
            return false;
        } else{
            for(int i=0;i<tree_leaf.size()/2;i++){
                if(tree_leaf.get(i)!=tree_leaf.get(i+tree_leaf.size()/2)){
                    return false;
                }
            }
        }
        return true;
    }
    public void recursive_middle_order(TreeNode t){
        if(t==null){
            return;
        }
        if(isleaf(t)==true) {
            tree_leaf.add(t.val);
            return;
        }

        recursive_middle_order(t.left);
        recursive_middle_order(t.right);

    }
    public boolean isleaf(TreeNode t){
        if(t.right==null&&t.left==null) return true;
        else return false;
    }
}
```