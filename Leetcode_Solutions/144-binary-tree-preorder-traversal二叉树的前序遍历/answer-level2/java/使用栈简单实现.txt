       1
      / \
     5   2
        /
       3 

使用迭代算法实现，需要借助栈。
每次遍历到一个节点时，先将它自身添加到结果集当中，并将它的右节点添加到栈当中。
此时，结果集：1   栈：2
然后遍历当前节点的左节点，并重复上述过程。
此时，结果集：1，5   栈：2
如果当前节点没有左节点了，则从栈中弹出栈顶元素，并继续重复上述过程。
此时，结果集：1，5，2   栈：空
再次遍历当前节点的左节点。
此时，结果集：1，5，2，3   栈：空
直到当前节点没有左节点，并且栈是空的情况下，结束遍历。
前序遍历的结果：1，5，2，3

翻译成代码如下：


```
class Solution {

    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        while (root != null || !stack.isEmpty()) {
            if (root != null) {
                result.add(root.val);
                if (root.right != null) stack.push(root.right);
                root = root.left;
            } else {
                root = stack.pop();
            }
        }
        return result;
    }

}
```
