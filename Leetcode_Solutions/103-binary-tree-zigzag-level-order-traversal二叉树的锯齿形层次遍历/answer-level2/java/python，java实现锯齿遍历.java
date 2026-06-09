python解法：
```
from collections import deque
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        levels = []
        if not root:
            return levels
        level = 0
        queue = deque([root, ])
        while queue:
            levels.append([])
            lens = len(queue)
            for i in range(lens):
                node = queue.popleft()
                if level % 2 == 0:
                    levels[level].append(node.val)
                else:
                    levels[level].insert(0, node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            level += 1
        return levels
```


Java解法：
```
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> levels = new ArrayList<List<Integer>>();
        if(root == null) return levels;
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        int level = 0;
        queue.add(root);
        while(!queue.isEmpty()) {
            levels.add(new ArrayList<Integer>());
            int lens = queue.size();
            for(int i = 0; i < lens; i++) {
                TreeNode p = queue.poll();
                if (level % 2 == 0) {
                    levels.get(level).add(p.val);
                } 
                else {
                    levels.get(level).add(0, p.val);//倒序输入数值满足要求，始终将其新的值放在最前面
                }
                if(p.left != null) queue.add(p.left);
                if(p.right != null) queue.add(p.right);
            }
            level++;
        }
        return levels;
    }
}
```
