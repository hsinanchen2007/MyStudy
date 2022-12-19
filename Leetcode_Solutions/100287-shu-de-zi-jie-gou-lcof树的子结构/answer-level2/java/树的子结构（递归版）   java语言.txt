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
    public boolean isSubStructure(TreeNode A, TreeNode B) {
          boolean result = false;

        if (A!=null && B!=null){
            // 根结点相同，紧接着判断子树结构一样不
            if (A.val == B.val){
                // 如果子树结构一样，返回true，也不用再对树A遍历了
                result = doesTree1HaveTree2(A,B);
            }
            // 当前根结点不同，或者即使根结点相同子树结构不同，还需继续遍历，递归判断左右子树
            if (!result){
                result = isSubStructure(A.left,B);
            }
            if (!result){
                result = isSubStructure(A.right,B);
            }
        }
        return result;
    }
     public boolean doesTree1HaveTree2(TreeNode node1,TreeNode node2){
        // 如果匹配子树到达叶子结点的左右子结点了都还相等，说明是树1的子结构
        if (node2==null){
            return true;
        }
        // 如果node2没有到叶子结点的左右子结点，而node1先到了说明匹配树比原来的树还大，返回false
        if (node1==null){
            return false;
        }

        if (node1.val != node2.val) {
            return false;
        }
        //递归其左右子节点，需要同时满足相等条件。
        return doesTree1HaveTree2(node1.left, node2.left) && doesTree1HaveTree2(node1.right, node2.right);
    }

}
```