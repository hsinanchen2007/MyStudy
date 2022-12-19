```java []
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        
        //相同点：大家都返回栈顶的值。不同点：peek 不改变栈的值(不删除栈顶的值)，pop会把栈顶的值删除
        Stack<TreeNode> stack = new Stack<>();
        ArrayList<Integer> result = new ArrayList<>();
        
        while (root != null){
            stack.push(root);
            root = root.left;
        }    //本次循环的结果是：把根节点的左子树依次入栈
        //判断最后一个入栈结点有没有右子树
        while (!stack.isEmpty())
        {
            TreeNode node = stack.peek();
            result.add(node.val);
        //没有右子树的话判断 这个点是不是上一节点的右子树
            if(node.right == null)
            {
                node = stack.pop();   
                while (!stack.isEmpty() && stack.peek().right == node){
                    node = stack.pop();  //如果这个点是上一节点右子树，则这个点的上一节点也出栈
                }
            }
        //有右子树的话，右子树入栈，再遍历左子树 
            else
            {
                node = node.right;
                while(node != null)
                {
                    stack.push(node);
                    node = node.left;
                }
            }    
        }
        return result;
    }