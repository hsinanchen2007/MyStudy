```
  public List<List<Integer>> levelOrderBottom(TreeNode root) {

        ArrayList<List<Integer>> lists = new ArrayList<>();
        if (root==null)
            return lists;

        Stack<List<Integer>> stack = new Stack<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()){

            int size=queue.size();
            ArrayList<Integer> list = new ArrayList<>();
            for (int i=0;i<size;i++){
                TreeNode node = queue.poll();
                list.add(node.val);
                if (node.left!=null)
                    queue.add(node.left);
                if (node.right!=null)
                    queue.add(node.right);
            }
            stack.push(list);
        }

        while (!stack.isEmpty()){
            lists.add(stack.pop());
        }
        return lists;


    }
```
