```
class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> ansList = new ArrayList<>();
        if (root == null) {
            return ansList;
        }
        Queue<Node> queue = new LinkedList<>();
        queue.offer(root);
        while (!queue.isEmpty()) {
            int size = queue.size();
            List<Integer> ans = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                Node node = queue.poll();
                ans.add(node.val);
                List<Node> children = node.children;
                if (children == null) {
                    continue;
                }
                for (Node child : children) {
                    queue.offer(child);
                }
            }
            ansList.add(ans);
        }
        return ansList;
    }
}
```
