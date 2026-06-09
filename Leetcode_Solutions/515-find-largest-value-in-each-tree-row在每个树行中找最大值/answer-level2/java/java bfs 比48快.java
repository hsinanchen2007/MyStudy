```
class Solution {
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> result = new LinkedList<>();
        if(root == null) return result; 

        LinkedList<TreeNode> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()){
            TreeNode temp;
            int maxV = Integer.MIN_VALUE;
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                temp = q.pollFirst();
                if (temp.val > maxV)
                    maxV = temp.val;
                if (temp.left != null)
                    q.add(temp.left);
                if (temp.right != null)
                    q.add(temp.right);
            }
            result.add(maxV);
        }
        return result;
    }
}
```
for控制当前层遍历。for(int i = 0; i < qsize; i++)写成了for(int i = 0; i < q.size(); i++)一开始没过，捂脸（for循环后面两个表达式会一直执行，所以q.size()会更新）
