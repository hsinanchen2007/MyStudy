### 解题思路
抛开本题，实现层序遍历有两种标准实现：递归、队列。
再看仔细观察本题要求输出的结果与标准实现有何不同？会发现只有一处不同：奇数层（层数从第 0 层开始）的插入顺序反了。即本该插入到列表尾的元素，在奇数层要插到列表头。

综上，只需在标准层级遍历的基础上，修改插入函数，让奇数层的插入顺序相反即可。

### 代码
插入函数：
``` java
    ... // 省略两种层级遍历的代码片段

    private void insert(TreeNode node, int level) {
        List<Integer> list = level >= ans.size() ? null : ans.get(level);
        if (list == null) {
            list = new LinkedList<>();
            list.add(node.val);
            ans.add(list);
        } else {
            boolean isOdd = (level & 1) == 1;
            list.add(isOdd ? 0 : list.size(), node.val);
        }
    }
```

解法一：
```java
class Solution {
    List<List<Integer>> ans = new LinkedList<>();
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        helper(root, 0);
        return ans;
    }

    private void helper(TreeNode root, int level) {
        if (root == null) {
            return;
        }
        insert(root, level);
        
        helper(root.left, level + 1);
        helper(root.right, level + 1);
    }
}
```

解法二：
```java
class Solution {
    List<List<Integer>> ans = new LinkedList<>();

    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if (root == null) {
            return ans;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        int level = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                insert(node, level);

                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
            }
            level++;
        }
        return ans;
    }
}
```