我的想法就是沿着树，从 target 往根结点 root 走，在以这条路径上的每个结点为根结点的子树中找根结点距离为 k 的子结点。距离是变化的，每往 root 走一步，k就变为 k - 1。并且不能去找这条路径上的子树。

```
class Solution {
    HashMap<TreeNode, TreeNode> map;
    HashSet<TreeNode> set;
    List<Integer> ans;
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        //map 用来存放部分结点及其祖先
        map = new HashMap<>();
        ans = new ArrayList<>();
        //set 用来存放 target 的祖先
        set = new HashSet<>();

        //找到 target 的祖先
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        map.put(root, null);
        while (!map.containsKey(target)) {
            TreeNode p = queue.poll();
            if (p.left != null) {
                map.put(p.left, p);
                queue.offer(p.left);
            }
            if (p.right != null) {
                map.put(p.right, p);
                queue.offer(p.right);
            }
        }

        //我们将按照从 target 沿着它的祖先结点进行深度优先搜索
        queue = new LinkedList<>();
        while (target != null) {
            set.add(target);
            queue.offer(target);
            target = map.get(target);
        }
        //此时 set 和 queue 里面都存放着 target 的祖先（包括target）
        while (!queue.isEmpty()) {
            //在以 target 祖先为根结点的树中找距离根结点距离为 k 的子结点
            //k 会随着访问祖先不断减一
            dfs(queue.poll(), K--);
            //可以在 k < 0 的时候 break
        }
        return ans;
    }

    public void dfs(TreeNode root, int k) {
        if (root == null) {
            return;
        }
        if (k == 0) {
            ans.add(root.val);
            return;
        }
        //不能再访问 target 的祖先结点
        if (root.left != null && !set.contains(root.left)) {
            dfs(root.left, k - 1);
        }
        if (root.right != null && !set.contains(root.right)) {
            dfs(root.right, k - 1);
        }
    }
}
```
