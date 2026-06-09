**其实这道题一看就很BFS，一层一层的往外扩，尤其是二叉树的特性，不用考虑循环，只要从左到右依赖队列的先进先出原理，就可以获得每一层外扩的所有结果，其实就是题目要求的层序遍历**
```
 public List<List<Integer>> levelOrder(TreeNode root) {
        //BFS
        List<List<Integer>> ans = new ArrayList<>();
        int count = 0;
        Queue<TreeNode> nodes = new LinkedList<>();
        nodes.offer(root);
        while (!nodes.isEmpty()) {
            int nums = (int) Math.pow(2, count);
            List<Integer> traces = new ArrayList<>();
            List<TreeNode> nexts = new ArrayList<>();
            //获取每一层的所有目的地
            while (nums != 0 && !nodes.isEmpty()) {
                TreeNode node = nodes.poll();
                if (node != null) {
                    traces.add(node.val);
                    //从左到右
                    nexts.add(node.left);
                    nexts.add(node.right);
                }
                nums--;
            }
            //添加下一层所有要走的目的地
            nexts.forEach(treeNode -> {
                nodes.offer(treeNode);
            });
            if (!traces.isEmpty()) {
                ans.add(traces);
            }
            count++;
        }

        return ans;
    }
```
