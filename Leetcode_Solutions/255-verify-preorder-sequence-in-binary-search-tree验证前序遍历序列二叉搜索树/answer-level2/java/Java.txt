这个题需要理解如下知识点：
- 先序遍历，如果递减，一定是左子树；
- 如果出现非递减的值，意味着到了某个节点的右子树；
- 利用栈来寻找该节点，最后一个比当前元素小的从栈弹出的元素即为该节点的父亲节点，而且当前元素父节点即为新的下限值；
- 后续的元素一定是比当前的下限值要大的，否则return false；
```
class Solution {
    public boolean verifyPreorder(int[] preorder) {
        Stack<Integer> stack = new Stack();
        int min = Integer.MIN_VALUE;
        for (int i = 0; i < preorder.length; i++) {
            if (preorder[i] < min) return false;
            while (!stack.isEmpty() && preorder[i]>stack.peek()){
                min = stack.pop();
            }
            stack.push(preorder[i]);
        }
        return true;
    }
}
```