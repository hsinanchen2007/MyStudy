**给定给目标和加上要求返回路径回溯在走就好了由于是二叉树因此就只有两种选择 往左往右 每做一次选择记得清理现场就好**
```
class Solution {
    List<List<Integer>> res = new LinkedList<>();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if(root==null) return res;
        LinkedList<Integer> in = new LinkedList<>();
        in.add(root.val);
        backTrack(root,root.val,sum,in);
        return res;
    }
    public void backTrack(TreeNode root,int curSum,int sum,LinkedList<Integer> list){
        if(root.left==null&&root.right==null){ //叶子节点
            if(curSum==sum){
                res.add(new LinkedList<>(list));
            }
            return ;
        }
        if(root.left!=null){
            list.add(root.left.val);
            backTrack(root.left,curSum+root.left.val,sum,list);
            list.removeLast();
        }
        if(root.right!=null){
            list.add(root.right.val);
            backTrack(root.right,curSum+root.right.val,sum,list);
            list.removeLast();
        }
    }
}
```
