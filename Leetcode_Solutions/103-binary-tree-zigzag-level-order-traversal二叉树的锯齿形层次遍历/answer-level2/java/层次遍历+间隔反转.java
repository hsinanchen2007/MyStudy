思路：层次遍历+间隔反转
这里使用的是队列进行层次遍历，每一层的遍历后使用null进行间隔，对每个节点的非空子树都进行进队（先左后右）。
其中隔层判断的技巧：队列中读到null时，说明该层已经读取完毕，可以加隔板了。
间隔反转：
这里使用了java的工具类Collections的反转方法，对上一步的结果进行进一步加工
```
private List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if (root == null) return new ArrayList<>();
        List<List<Integer>> res = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        queue.offer(null);
        List<Integer> addIndex = new ArrayList<>();
        boolean rover = false;
        while (!queue.isEmpty()) {
            TreeNode temp = queue.poll();
            if (temp == null) {
                res.add(addIndex);
                if (queue.isEmpty()) break;
                queue.offer(null);
                addIndex = new ArrayList<>();
            } else {
                if (temp.left != null) queue.offer(temp.left);
                if (temp.right != null) queue.offer(temp.right);
                addIndex.add(temp.val);
            }
        }
        for (List<Integer> idx : res) {
            if (rover) {
                Collections.reverse(idx);
            }
            rover = !rover;
        }
        return res;
    }
```
