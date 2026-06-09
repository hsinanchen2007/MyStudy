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
    private List<Integer> allElementsList;

    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        allElementsList = new ArrayList<>();

        TreeIterator tI1 = new TreeIterator(root1);
        TreeIterator tI2 = new TreeIterator(root2);
        TreeNode t1 = null;
        TreeNode t2 = null;

        while ((tI1.hasNext() || t1!=null) && (tI2.hasNext() || t2!=null)) {
            if (null == t1)
                t1 = tI1.next();
            if (null == t2)
                t2 = tI2.next();

            if (t1.val < t2.val) {
                allElementsList.add(t1.val);
                System.out.println("T1: " + t1.val);
                t1 = null;
            } else {
                allElementsList.add(t2.val);
                System.out.println("T2: " + t2.val);
                t2 = null;
            }
        }

        if (!tI1.hasNext() && !tI2.hasNext() && tI1 == null && tI2 == null)
            return allElementsList;

        TreeIterator lastIter = tI1.hasNext() ? tI1 : tI2;
        TreeNode lastNode = t1 == null ? t2: t1;
        if (null != lastNode) {
            allElementsList.add(lastNode.val);
            System.out.println("LastNode: " + lastNode.val);
        }
        while (lastIter.hasNext()) {
            allElementsList.add(lastIter.next().val);
        }

        return allElementsList;
    }

    class TreeIterator implements Iterator<TreeNode> {
        //中序遍历迭代器

        private Stack<TreeNode> stack;

        TreeIterator(TreeNode root) {
            stack = new Stack<>();
            pushLeftPath(root);
        }

        @Override
        public boolean hasNext() {
            return !stack.isEmpty();
        }

        private void pushLeftPath(TreeNode node) {
            while (null != node) {
                stack.push(node);
                node = node.left;
            }
        }

        @Override
        public TreeNode next() {
            if (stack.isEmpty())
                return null;

            TreeNode ret = stack.pop();
            pushLeftPath(ret.right);
            return ret;
        }
    }

}
```