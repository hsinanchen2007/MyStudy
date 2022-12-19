BFS队列维护所有元素，出一个元素，将下一层的元素入队列；
分层处理，确保每一层处理完，在进入到下一层的处理；
每一层处理后，将最后一个元素入结果队列；


class Solution {
    public List<Integer> rightSideView(TreeNode root) {

        List<Integer> ret = new ArrayList();

        if (root == null) {
            return ret;
        }

        LinkedList<TreeNode> q = new LinkedList<>();

        q.add(root);
        while (!q.isEmpty()) {

            ret.add(q.getLast().val);

            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                if (q.getFirst().left != null) {
                    q.add(q.getFirst().left);
                }
                if (q.getFirst().right != null) {
                    q.add(q.getFirst().right);
                }
                q.removeFirst();
            }

        }

        return ret;

    }
}