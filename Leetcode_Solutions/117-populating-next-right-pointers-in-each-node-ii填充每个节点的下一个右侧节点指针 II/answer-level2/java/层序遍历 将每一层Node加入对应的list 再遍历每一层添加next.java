class Solution {
    public Node connect(Node root) {
        if (root == null) return null;
        ArrayList<List<Node>> list = new ArrayList<>();
        Queue<Node> queue = new LinkedList<>();
        Node curr;
        int level = 0;
        queue.offer(root);
        //层序遍历将node加入每一层的list
        while (!queue.isEmpty())
        {
            list.add(new ArrayList<>());
            int len = queue.size();
            for (int i = 0; i<len;i++)
            {
                curr = queue.poll();
                list.get(level).add(curr);
                if (curr.left != null) queue.offer(curr.left);
                if (curr.right!= null) queue.offer(curr.right);
            }
            level++;
        }
        for (List<Node> currList:list)
        {
            for (int i =0;i<currList.size()-1;i++)
            {
                currList.get(i).next = currList.get(i+1);
            }
        }
        return root;
    }
}
执行用时 :4 ms, 在所有 Java 提交中击败了40.72%的用户
内存消耗 :51.5 MB, 在所有 Java 提交中击败了97.29%的用户