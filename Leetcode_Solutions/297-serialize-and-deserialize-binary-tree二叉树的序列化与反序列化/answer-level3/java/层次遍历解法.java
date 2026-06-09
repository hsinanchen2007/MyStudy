LeetCode序列化二叉树的格式可参考LeetCode国际站点：<https://support.leetcode.com/hc/en-us/articles/360011883654-What-does-1-null-2-3-mean-in-binary-tree-representation->


``` java
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null) {
            return "";
        }
        final TreeNode nullObject = new TreeNode(-1);
        List<TreeNode> levelNodes = new LinkedList<>();
        levelNodes.add(root);
        Deque<TreeNode> traversal = new LinkedList<>();
        while (!levelNodes.isEmpty()) {
            List<TreeNode> nextLevelNodes = new LinkedList<>();
            for (TreeNode node : levelNodes) {
                traversal.add(node);
                if (node.equals(nullObject)) {
                    continue;
                }
                if (node.left != null) {
                    nextLevelNodes.add(node.left);
                } else {
                    nextLevelNodes.add(nullObject);
                }

                if (node.right != null) {
                    nextLevelNodes.add(node.right);
                } else {
                    nextLevelNodes.add(nullObject);
                }
            }
            levelNodes = nextLevelNodes;
        }
        // remove tail nullObjects
        while (traversal.peekLast().equals(nullObject)) {
            traversal.pollLast();
        }
        return traversal.stream().map(node -> {
            if (node.equals(nullObject)) {
                return "null";
            } else {
                return Integer.toString(node.val);
            }
        }).collect(Collectors.joining(","));
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data.isEmpty()) {
            return null;
        }
        final String nullStr = "null";
        final String[] split = data.split(",");
        final TreeNode root = new TreeNode(Integer.parseInt(split[0]));
        List<TreeNode> preLevel = new LinkedList<>();
        preLevel.add(root);
        int i = 1;
        while (!preLevel.isEmpty()) {
            List<TreeNode> thisLevel = new LinkedList<>();
            for (TreeNode parent : preLevel) {
                if (i < split.length && !split[i].equals(nullStr)) {
                    final TreeNode leftChild = new TreeNode(Integer.parseInt(split[i]));
                    parent.left = leftChild;
                    thisLevel.add(leftChild);
                }
                if (i + 1 < split.length && !split[i + 1].equals(nullStr)) {
                    final TreeNode rightChild = new TreeNode(Integer.parseInt(split[i + 1]));
                    parent.right = rightChild;
                    thisLevel.add(rightChild);
                }
                i += 2;
            }
            preLevel = thisLevel;
        }
        return root;
    }
}
```
