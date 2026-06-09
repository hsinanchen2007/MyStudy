常规做法：用一个二维列表List<List<Integer>>存储每一层不为null的值，最后返回列表最后一行的第一个数
java code:
```
class Solution {
    public int findBottomLeftValue(TreeNode root) {
        Queue<TreeNode> q=new LinkedList<>();
        List<List<Integer>> result=new ArrayList<>();
        q.offer(root);
        int num=1;
        int newNum=0;
        while(!q.isEmpty())
        {
            newNum=0;
            List<Integer> line=new ArrayList<>();
            for(int i=0;i<num;i++)
            {
                TreeNode t=q.poll();
                line.add(t.val);
                if(t.left!=null)
                {
                    q.offer(t.left);
                    newNum++;
                }
                if(t.right!=null)
                {
                    q.offer(t.right);
                    newNum++;
                }
            }
            result.add(line);
            num=newNum;
        }
        return result.get(result.size()-1).get(0);
    }
}
```
