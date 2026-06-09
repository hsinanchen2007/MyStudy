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
    public int pathSum(TreeNode root, int sum) {
        if (root == null) {
            return 0;
        }

        int total = 0;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();

            total += subSum(node,sum);

            if (node.left != null) {
                queue.offer(node.left);
            }

            if (node.right != null) {
                queue.offer(node.right);
            }
        }

        return total;
    }

    private int subSum(TreeNode root, int sum) {
        if (root == null) {
            return 0;
        }

        int total = 0;

        Stack<Pair<TreeNode, List<Integer>>> stack = new Stack<>();

        List<Integer> list = new ArrayList<>();
        list.add(root.val);
        stack.push(new Pair<>(root, list));

        while (!stack.isEmpty()) {
            Pair<TreeNode, List<Integer>> pair = stack.pop();
            TreeNode node = pair.getKey();
            List<Integer> totalList = pair.getValue();

            if (sum(totalList) == sum) {
                total++;
            }

            if (node.left != null) {
                List leftList = new ArrayList();
                leftList.addAll(totalList);
                leftList.add(node.left.val);

                stack.push(new Pair<>(node.left, leftList));
            }

            if (node.right != null) {
                List<Integer> rightList = new ArrayList<>();
                rightList.addAll(totalList);
                rightList.add(node.right.val);

                stack.push(new Pair<>(node.right, rightList));
            }
        }

        return total;
    }

    private int sum(List<Integer> list) {
        int sum = 0;
        for (Integer val : list) {
            sum += val;
        }
        return sum;
    }
}
```