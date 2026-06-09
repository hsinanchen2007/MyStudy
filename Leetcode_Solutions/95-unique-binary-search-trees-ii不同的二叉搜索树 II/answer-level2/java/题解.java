### 解题思路
借鉴了题解中的做法，递归，每次传入要进行组合的数值区间，在每个递归中枚举区间中的数值，作为根结点，再调用函数找到所有的左右子树进行遍历

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
    public List<TreeNode> generateTrees(int n) {
        if (n == 0)  return new ArrayList<TreeNode>(0);
        return f(1, n);
    }

    List<TreeNode> f(int start, int end) {
        List<TreeNode> trees = new ArrayList<>();
        if (start == end) {
            trees.add(new TreeNode(start));
            return trees;
        };
        if (start > end) {
            trees.add(null);
            return trees;
        };
        for (int i = start; i <= end; i++) {
            List<TreeNode> leftTrees = f(start, i - 1);
            List<TreeNode> rightTrees = f(i + 1, end);
            for (TreeNode leftTree : leftTrees) {
                for (TreeNode rightTree : rightTrees) {
                    TreeNode t = new TreeNode(i);
                    t.left = leftTree;
                    t.right = rightTree;
                    trees.add(t);
                }
            }
        }
        return trees;
    }
}
```