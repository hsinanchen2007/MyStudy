## 代码
```java
//非递归解法
public List<List<Integer>> levelOrder1(TreeNode root) {

        List<List<Integer>> lists = new ArrayList<>();

        if (root == null) {
            return lists;
        }
        LinkedList<TreeNode> nodeList = new LinkedList<>();
        nodeList.add(root);
        while (!nodeList.isEmpty()) {
            List<Integer> list = new ArrayList<>();
            int cnt = nodeList.size();
            while (cnt-- > 0) {
                TreeNode tmp = nodeList.removeFirst();
                list.add(tmp.val);
                if (tmp.left != null) {
                    nodeList.add(tmp.left);
                }
                if (tmp.right != null) {
                    nodeList.add(tmp.right);
                }
            }
            lists.add(list);
        }
        return lists;

    }

//递归解法
public List<List<Integer>> levelOrderDFS(TreeNode root) {
        DFS(root, 0);
        return lists;

    }

    private void DFS(TreeNode root, int level) {
        if (root == null) {
            return;
        }
        //当前层数还没有元素，先new一个空的列表
        if (lists.size() <= level) {
            lists.add(new ArrayList<>());
        }
        //当前值加入
        lists.get(level).add(root.val);
        DFS(root.left, level + 1);
        DFS(root.right, level + 1);
    }

```