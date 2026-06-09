### 解题思路
二叉搜索树是left < root < right的，先序遍历又是root->left->right的，基于这样的性质和遍历方式，我们知道越往左越小，这样，就可以构造一个单调递减的栈，来记录遍历的元素。

为什么要用单调栈呢，因为往左子树遍历的过程，value是越来越小的，一旦出现了value大于栈顶元素value的时候，就表示要开始进入右子树了（如果不是，就应该继续进入左子树，不理解的请看下二叉搜索树的定义），但是这个右子树是从哪个节点开始的呢？

单调栈帮我们记录了这些节点，只要栈顶元素还比当前节点小，就表示还是左子树，要移除，因为我们要找到这个右孩子节点直接连接的父节点，也就是找到这个子树的根，只要栈顶元素还小于当前节点，就要一直弹出，直到栈顶元素大于节点，或者栈为空。栈顶的上一个元素就是子树节点的根。

接下来，数组继续往后遍历，之后的右子树的每个节点，都要比子树的根要大，才能满足，否则就不是二叉搜索树

### 代码

```java
class Solution {
    public boolean verifyPreorder(int[] preorder) {
        // 单调栈使用，单调递减的单调栈
        Deque<Integer> stack = new LinkedList<>();
        Integer prevElement = Integer.MIN_VALUE;// 这个表示上一个栈顶元素，初始化最小值，是避免多次判空
        for (int i = 0;i<preorder.length;i++){
            // 右子树元素必须要大于递减栈被peek访问的元素，否则就不是二叉搜索树
            if (preorder[i] < prevElement){
                return false;
            }
            while (!stack.isEmpty() && preorder[i] > stack.peek()){
                // 数组元素大于单调栈的元素了，表示往右子树走了，记录下上个根节点
                // 找到这个右子树对应的根节点，之前左子树全部弹出，不在记录，因为不可能在往根节点的左子树走了
                prevElement = stack.pop();
            }
            // 这个新元素还是要进去
            stack.push(preorder[i]);
        }
        return true;
    }
}
```