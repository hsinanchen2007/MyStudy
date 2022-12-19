递归解：
```
class Solution {//递归解
    int minH = Integer.MAX_VALUE;
    public int minDepth(TreeNode root) {
        if(root == null){
            return 0;
        }
        mind(root, 1);
        return minH;
    }
    public void mind(TreeNode root,int level){
        if(root!=null){
            if(root.left == null && root.right == null){
                minH = Math.min(minH, level);
            }
            //show it
            mind(root.left, level+1);
            mind(root.right, level+1);
        }
    }
}
```
递推解：
```
public int minDepth(TreeNode root) {//递推解
        int res = 1;
        if(root == null) return 0;
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.add(root);
        while(!queue.isEmpty()){
            int n = queue.size();
            for(int i=0;i<n;i++){
                TreeNode curNode = queue.poll();
                if(curNode.left == null && curNode.right == null){//遇到就及时跳出
                    return res;
                }
                if(curNode.left!=null){
                    queue.add(curNode.left);
                }if(curNode.right!=null){
                    queue.add(curNode.right);
                }
            }
            res ++ ;
        }
        return res;//最后的结果是一棵满二叉树
    }
```

