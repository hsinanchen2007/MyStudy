### 解题思路
后序遍历:左右根
递归形式比较简单
使用呢栈模拟:压栈的顺序是根-左-右,根直接加入到list中,从栈中弹出的顺序是右-左,每一次弹出的元素都加入到结果集合的第一个元素上面

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
    //递归形式
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result=new ArrayList<>();
        postorderTraversal(root,result);
        return result;
    }
    private void postorderTraversal(TreeNode root,List<Integer> result){
        if(root==null){
            return;
        }
        postorderTraversal(root.left,result);
        postorderTraversal(root.right,result);
        result.add(root.val); 
    }
    //使用栈
    public List<Integer> postorderTraversal(TreeNode root){
        //使用了LinkedList
        LinkedList<Integer> result=new LinkedList<>();
        if(root==null){
            return new LinkedList<>();
        }
        
        Stack<TreeNode> stack=new Stack<>();
        stack.push(root);
        while(!stack.isEmpty()){
            TreeNode node=stack.pop();
            //保存根节点,添加到第一个元素位置使用addFirst
            result.addFirst(node.val);
            //压栈顺序是左-右的顺序
            if(node.left!=null){
                stack.push(node.left);
            }
            if(node.right!=null){
                stack.push(node.right);
            }
        }
        return result;
    }

```