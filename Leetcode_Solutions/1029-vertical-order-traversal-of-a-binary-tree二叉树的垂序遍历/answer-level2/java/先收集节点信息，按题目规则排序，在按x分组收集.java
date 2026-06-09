```
class Solution {
    public static class Node {
        public int x;
        public int y;
        public int val;
        public Node(int x, int y, int val) {
            this.x = x;
            this.y = y;
            this.val = val;
        }
    }

    // 先将所有节点的坐标和值收集起来，然后按照题目中的规则对这些节点排序，最后按照坐标x的值进行收集
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null) return ans;
        List<Node> list = new ArrayList<>();
        // 收集所有节点信息
        collect(list, root, 0, 0);
        // 定义排序规则并排序
        list.sort((node1, node2) -> {
            int x1 = node1.x;
            int y1 = node1.y;
            int v1 = node1.val;
            int x2 = node2.x;
            int y2 = node2.y;
            int v2 = node2.val;
            // x小的在前
            if (x1 != x2) return x1 - x2;
            // y大的在前
            if (y1 != y2) return y2 - y1;
            // 节点值小的在前
            return v1 - v2;
        });
        
        // 对所有x相同的节点分组收集
        int i = 0;
        do {
            int x = list.get(i).x;
            List<Integer> l = new ArrayList<>();
            while (i < list.size() && x == list.get(i).x) {
                l.add(list.get(i).val);
                ++i;
            }
            ans.add(l);
        } while (i != list.size());
        
        return ans;
    }

    // 收集所有节点的信息
    private void collect(List<Node> list, TreeNode root, int x, int y) {
        if (root == null) {
            return;
        }
        list.add(new Node(x, y, root.val));
        if (root.left != null) {
            collect(list, root.left, x - 1, y - 1);
        }
        if (root.right != null) {
            collect(list, root.right, x + 1, y - 1);
        }
    }
}
```
