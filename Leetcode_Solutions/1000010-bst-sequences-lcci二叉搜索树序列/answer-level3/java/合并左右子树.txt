### 解题思路
该题解源于书上的解答。
第一个插入的元素一定是二叉搜索树的根节点。插入根节点后，其余的元素分别位于左子树和右子树中。对左子树和右子树递归得到相应的序列，然后合并。
需要实现两个递归方法，第一个递归方法是主方法，第二个递归方法是合并方法。在第二个递归方法中，维护一个前缀序列，左右子树序列的元素都必须在前缀序列之后。
二叉搜索树的特点决定了不存在重复元素，因此不需要去重。

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
    public List<List<Integer>> BSTSequences(TreeNode root) {
        List<List<Integer>> sequences = new ArrayList<List<Integer>>();
        if (root == null) {
            sequences.add(new LinkedList<Integer>());
            return sequences;
        }
        List<Integer> prefix = new LinkedList<Integer>();
        prefix.add(root.val);
        List<List<Integer>> leftSequences = BSTSequences(root.left);
        List<List<Integer>> rightSequences = BSTSequences(root.right);
        for (List<Integer> leftSequence : leftSequences) {
            for (List<Integer> rightSequence : rightSequences) {
                List<List<Integer>> mergedSequences = new ArrayList<List<Integer>>();
                merge(leftSequence, rightSequence, mergedSequences, prefix);
                sequences.addAll(mergedSequences);
            }
        }
        return sequences;
    }

    public void merge(List<Integer> leftSequence, List<Integer> rightSequence, List<List<Integer>> mergedSequences, List<Integer> prefix) {
        if (leftSequence.size() == 0 || rightSequence.size() == 0) {
            List<Integer> mergedSequence = new LinkedList<Integer>(prefix);
            mergedSequence.addAll(leftSequence);
            mergedSequence.addAll(rightSequence);
            mergedSequences.add(mergedSequence);
        } else {
            int leftHead = leftSequence.remove(0);
            prefix.add(leftHead);
            merge(leftSequence, rightSequence, mergedSequences, prefix);
            prefix.remove(prefix.size() - 1);
            leftSequence.add(0, leftHead);
            int rightHead = rightSequence.remove(0);
            prefix.add(rightHead);
            merge(leftSequence, rightSequence, mergedSequences, prefix);
            prefix.remove(prefix.size() - 1);
            rightSequence.add(0, rightHead);
        }
    }
}
```