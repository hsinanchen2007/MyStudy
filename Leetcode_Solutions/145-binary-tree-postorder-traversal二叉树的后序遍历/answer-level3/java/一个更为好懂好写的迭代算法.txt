递归和前序遍历的反向，这两种方法很简单，不多说，这里说一下真的后序遍历。

依然是栈的思想，但是做了一点点优化（性能上我估计没什么优化，主要是更容易理解和编写）

将根节点入栈，然后循环体如下：
1. 查看栈顶元素top，
2. 如果top有左节点，则把左节点入栈（此时栈顶变为了左节点）。
3. 如果top没左节点，但是有右节点，则把右节点入栈。
4. 如果top左右节点都没有，直接输出该节点并出栈。

但是有个小问题，那就是：当某一个节点A的左子树全部输出完毕且出栈后，栈顶又会是A，又会回到第一种情况，会进入死循环。
于是我们在A的左节点入栈的时候，将A.left置为null。右节点同理。
这样，任意一个节点的左子树输出后，该节点的left已经变成了null，会自然的将右子树入栈。
而右子树也输出完毕后，该节点的left和right都被置为了null，该节点就会自然的输出并出栈。

下面就是代码，比常规迭代解法更好写，更好懂。

```java []
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        LinkedList<Integer> ans = new LinkedList<>();
        LinkedList<TreeNode> stack = new LinkedList<>();
        if(root == null)return ans;
        TreeNode tmp;
        
        stack.addFirst(root);
        while(stack.size() > 0){
            tmp = stack.getFirst();
            if(tmp.left!=null){
                stack.addFirst(tmp.left);
                tmp.left = null;
            }else if(stack.getFirst().right!=null){
                stack.addFirst(tmp.right);
                tmp.right = null;
            }else
                ans.add(stack.pop().val);
        }
        return ans;
    }
}
```

