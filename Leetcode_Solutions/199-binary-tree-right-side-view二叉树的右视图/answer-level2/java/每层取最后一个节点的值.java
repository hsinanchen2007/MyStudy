提交结果：
执行用时 :1 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :36.1 MB, 在所有 Java 提交中击败了40.00%的用户


思路：就是一层一层遍历，但是遍历的方式有很多种。我第一次用两个队列，一个队列表示一层，分表表示父子代，最终结果是6ms，秒杀全场7%的同学。这肯定不能忍啊，最后找到使用一个哨兵节点来标志一层的结束，每次出列的是哨兵说明上一层遍历完了，记录上一个节点的值。如果此时队列为空说明没有下一层，结束，否则哨兵重新入列来表示下一层的结尾。


代码：
```
public List<Integer> rightSideView(TreeNode root) {
        //收集每一层最右边的节点
        List<Integer> res=new ArrayList<>();
        if (root==null)return res;//空树
        LinkedList<TreeNode> queue=new LinkedList<>();
        TreeNode shaoBing=new TreeNode(0);//哨兵节点
        queue.add(root);
        queue.add(shaoBing);
        int last=0;
        while (!queue.isEmpty()){
            TreeNode poll = queue.poll();
            if (poll==shaoBing){//遇到哨兵表示一层遍历完成
                res.add(last);
                if (queue.isEmpty())break;//没有下一层了
                else queue.add(shaoBing);//右下一层则重新入列，标志层尾
            }
            else {
                last=poll.val;
                if (poll.left!=null)queue.add(poll.left);
                if (poll.right!=null)queue.add(poll.right);
            }
        }
        return res;
    }
```
