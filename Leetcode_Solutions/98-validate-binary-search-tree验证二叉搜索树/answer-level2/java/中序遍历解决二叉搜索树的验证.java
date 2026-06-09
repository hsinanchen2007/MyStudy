### 解题思路
根据二叉搜索树的性质，即中序遍历所有节点值，这些值是有序的，如果出现无序的，则错误，
一点点改变就是在中序遍历过程中如果有节点不满足要求，则直接返回false，无需中序遍历整个树，减少了一定1时间，
时间复杂度：O（n），n是节点的总数
空间复杂度：O（n），n是节点的总数，空间开销来源于对所有节点的值存储

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
    public boolean isValidBST(TreeNode root) {
        if(root == null) {
            return true;
        }
        return midSearch(root, new ArrayList<>());
    }

    public boolean midSearch(TreeNode node, List<Integer> midResult) {
        boolean leftResult = true;
        boolean rightResult = true;
        if (node.left != null) {
            leftResult = midSearch(node.left, midResult);
        }
        if (!leftResult) {
            return false;
        }
        if(midResult.size() == 0) {
            midResult.add(node.val);
        } else {
            int last = midResult.get(midResult.size()-1).intValue();
            if (node.val <= last) {
                return false;
            }
            midResult.add(node.val);
        }
        
        if(node.right != null) {
            rightResult = midSearch(node.right, midResult);
        }
        return rightResult;
    }

}
```