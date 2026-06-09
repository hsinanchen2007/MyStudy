```
class Solution {
    /**
     * 先中序遍历获取该二叉树的排序，查出哪两个元素的位置是错误的。
     * 然后再进行一次遍历,找出错误位置的两个数。
     * 再根据修改后的中序序列，DFS遍历交换这两个节点的值
     */
    public   void recoverTree(TreeNode root) {
        List<Integer> inOrder=inOrder(root);
        List<Integer> nums=findNumber(inOrder);
        //层次遍历，发现为arr[0]则交换为arr[1]，发现为arr[1]则交换为arr[0]
        Queue<TreeNode> queue=new LinkedList<TreeNode>();
        queue.add(root);
        while(!queue.isEmpty()){
            TreeNode node=queue.poll();
            if(node.val==nums.get(0)){
                node.val=nums.get(1);
            }else if(node.val==nums.get(1)){
                node.val=nums.get(0);
            }
            if(node.left!=null){
                queue.add(node.left);
            }
            if(node.right!=null){
                queue.add(node.right);
            }
        }
    }

    public  List<Integer> findNumber(List<Integer> list){
        List<Integer> temp=new ArrayList<Integer>(list.size());
        for(int i=0;i<list.size();i++){
            temp.add(list.get(i));
        }
        List<Integer> res=new ArrayList<Integer>(2);
        Collections.sort(list);
        for(int i=0;i<list.size();i++){
            if(temp.get(i)!=list.get(i)){
                res.add(temp.get(i));
            }
        }
        return res;
    }

    public  List<Integer> inOrder(TreeNode node){
        List<Integer> res=new ArrayList<Integer>();
        if(node==null) return  res;
        Stack<TreeNode> stack=new Stack<TreeNode>();
        stack.add(node);
        HashSet<TreeNode> set=new HashSet<TreeNode>();
        while(!stack.isEmpty()){
            TreeNode temp=stack.peek();

            if(temp.left!=null && !set.contains(temp.left)){
                stack.add(temp.left);
                continue;
            }

            if(!set.contains(temp)){
                res.add(temp.val);
                set.add(temp);
            }

            if(temp.right!=null && !set.contains(temp.right)){
                stack.add(temp.right);
                continue;
            }
            stack.pop();
        }
        return res;
    }
}
```
