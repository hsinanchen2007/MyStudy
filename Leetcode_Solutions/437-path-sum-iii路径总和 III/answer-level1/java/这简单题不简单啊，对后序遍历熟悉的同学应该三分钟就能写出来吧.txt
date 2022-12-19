思路就是：
从根节点开始，首先计算以根节点开始的路径有多少个（通过后序遍历的方式，遍历所有节点，可以得出）计为sumroot
对左右子节点，递归，得到sumleft和sumright。
所以总路径sumall=sumroot+sumleft+sumright。

后序遍历二叉树，用一个cursum表示当前路径和，
在压栈的时候计算cursum加压入栈节点的值，然后判断是否为目标sum，是就count++
在出栈的时候，cursum加弹出栈节点的值

最后返回count


应该没有比我这个更复杂的了吧。
时间复杂度n2，空间复杂度n


class Solution {
    public int pathSum(TreeNode root, int sum) {
        if(root==null)
        return 0;
        int count=0;
        count+=helper(root,sum);
        if(root.left!=null)
        count+=pathSum(root.left,sum);
        if(root.right!=null)
        count+=pathSum(root.right,sum);
        return count;
    }
    public int helper(TreeNode root, int sum) {
        Stack<TreeNode> stack = new Stack<>();
        Stack<Integer> stack2 = new Stack<>();
        int cursum = 0 ;
        int left=1;
        int right=2;
        int count=0;
        while (!stack.isEmpty()||root!=null)
        {
            while (root!=null)
            {
                stack.push(root);
                cursum+=root.val;
                if (cursum==sum)
                    count+=1;
                root=root.left;
                stack2.push(left);
            }
            while (!stack.isEmpty()&&stack2.peek()==right)
            {
                stack2.pop();
                cursum-=stack.pop().val;
            }
            if (!stack.isEmpty()&&stack2.peek()==left)
            {
                stack2.pop();
                stack2.push(right);
                root=stack.peek().right;
            }
        }
        return  count;
    }
}