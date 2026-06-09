class Solution {
    public int countNodes(TreeNode root) {
        if(root==null){
            return 0;
        }
Queue<TreeNode> queue=new LinkedList();
Stack<TreeNode> stack=new Stack();
Stack<TreeNode> kk=new Stack();
queue.offer(root);
while(!queue.isEmpty()){
TreeNode hh=queue.poll();
if(hh.left!=null){
    queue.offer(hh.left);
    if(hh.right!=null){
        queue.offer(hh.right);}
        stack.push(hh);
    }
if(hh.left==null&&hh.right==null){
    kk.push(hh);
}
}

int a=0; int b=0;
while(!stack.isEmpty()){
    a++;
    stack.pop();
}
while(!kk.isEmpty()){
    b++;
    kk.pop();
}

return a+b;

    }
}
