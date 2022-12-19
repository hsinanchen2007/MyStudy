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
    private List<List<Integer>> rlist = new ArrayList<>();

    public int sumRootToLeaf(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        helper(root, list);

        return getSum(rlist);

    }

    void helper(TreeNode root, List list) {
        if (root == null) return;

        if (root.left == null & root.right == null) {
            LinkedList<Integer> copy = new LinkedList<>(list);
            copy.add(root.val);
            rlist.add(copy);
            return;
        }

        list.add(root.val);

        helper(root.left, list);
        helper(root.right, list);

        list.remove(list.size() - 1);

    }

    int binaryToDecimal(List<Integer> list) {
        String s = "";
        for (Integer item : list) {
            s += item;
        }
        return Integer.valueOf(s + "", 2);
    }

    int getSum(List<List<Integer>> list) {
        List<Integer> dList = new LinkedList<>();
        int sum = 0;
        for (List<Integer> item : list) {
            sum += binaryToDecimal(item);
        }
        return sum;
    }
}
```