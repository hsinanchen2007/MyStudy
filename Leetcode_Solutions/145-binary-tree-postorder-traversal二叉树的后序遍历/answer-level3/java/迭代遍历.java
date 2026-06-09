### 解题思路
迭代的方法后序遍历的难点是,遍历完一个结点的左子树后,不能把当前结点弹出,而是要继续遍历右子树.`node = stack.peek().right;`,取右子结点继续按照之前的方法遍历一遍.
因此,对于一个结点,它能不能被弹出,有两个条件:

1. 没有左子结点或者左子结点被遍历过了
没有左子结点很好判断,在循环里取`node = node.left`,node为空的时候就行了.
关于左子结点被遍历过了这个条件,因为我们知道在stack中,结点的左子结点一定在这个结点的后面,也就是比它先pop,如果一个结点是stack中最后一个结点,说明它的左子结点肯定pop过了,所以这一点不用加额外的判断,到了这个结点,说明左子结点肯定判断过了.

2. 没有右子结点或者右子结点被遍历过了.
当我们要判断完一个结点的条件1后,还得先判断`node = stack.peek().right;`为不为空.为空的话就可以直接pop并加入result了.
如果不为空,可以将右子结点,也就是右子树重复一遍操作.但问题是,这里有可能会重复遍历右子树,所以,我们得用一个lastNode记录下上一次pop的结点.如果一个结点的右子结点就是上次pop的结点,那就说明右子树被遍历过了.为什么只要记一个lastNode呢?因为后序遍历是左-右-上,当一个结点被放进结果时,如果它右右子结点,那么上一个结点一定是它的右子结点.

所以,总的思路是,先循环将左子结点入栈,没有左子结点后,如果有右子结点,再对右子结点执行一遍操作.当没有左子结点和右子结点时,出栈,加入到result中,然后取stack.peek,也就是刚刚放入结果的结点的父结点,然后取父结点的右子结点,再执行一遍判断.为了防止右子结点出栈后,'stack.peek.right'又取到了遍历过的右结点,重复遍历右子树,所以加了个lastNode来判断有没有遍历过右子结点.如果已经遍历过右子结点了,那么将父结点出栈.重复之前的循环,直到根结点出栈,结束循环.

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
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {

        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }
        Stack<TreeNode> stack = new Stack<>();
        TreeNode node = root;
        TreeNode lastNode = null;
        while (node != null || !stack.isEmpty()) {
            while (node != null && node != lastNode) {
                stack.add(node);
                node = node.left;
            }
            node = stack.peek().right;
            if (node == null || node == lastNode) {
                lastNode = stack.pop();
                result.add(lastNode.val);
                if (stack.isEmpty()) {
                    break;
                }
                node = stack.peek().right;
            }
        }
        return result;
    }
}
```