```
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        Queue<Pair> queue = new LinkedList<>();
        if (root != null) {
            queue.offer(new Pair(root, 0));
        }
        List<List<Integer>> ret = new ArrayList<>();
        List<Integer> item = new ArrayList<>();
        int depth = 0;
        while (!queue.isEmpty()) {
            Pair top = queue.poll();
            //System.out.println(top.node.val);
            if (top.depth == depth) {
                item.add(top.node.val);
            } else {
                if (depth % 2 == 1) {
                    Collections.reverse(item);
                }
                ret.add(item);
                depth++;
                item = new ArrayList<>();
                item.add(top.node.val);
            }
            if (top.node.left != null) queue.offer(new Pair(top.node.left, top.depth + 1));
            if (top.node.right != null) queue.offer(new Pair(top.node.right, top.depth + 1));
            
        }
        if (!item.isEmpty()) { // 最后一层遍历未加入，在最后加入
            if (depth % 2 == 1) { // 判断是否需要reverse
                Collections.reverse(item);
            }
            ret.add(item);
        }
        return ret;
    }
}

class Pair {
    TreeNode node;
    int depth;
    Pair(TreeNode node, int depth) {
        this.node = node;
        this.depth = depth;
    }
}
```
