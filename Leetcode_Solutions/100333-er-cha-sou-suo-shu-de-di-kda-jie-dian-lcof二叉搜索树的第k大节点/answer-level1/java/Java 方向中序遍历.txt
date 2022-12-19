实际上，这道题使用迭代和递归的思想都是一致的。
迭代本质上是利用一个栈去遍历整棵树，而递归的流程跟栈很相似。

解法一：递归
    
```
class Solution {
        int k;
        int res;
        public int kthLargest(TreeNode root, int k) {

            this.k  = k;
            res = -1;
            kthLargest(root);
            return res;
        }
        private void kthLargest (TreeNode root){
            if(root == null) return;
            kthLargest(root.right);


            if(--k == 0) {
                res = root.val;
                return;
            }

            kthLargest(root.left);
        }
    }
```

解法二：非递归（迭代） 栈实现
```
Class Solution{
    public int kthLargest(TreeNode root, int k) {
        int count = 0;
        Stack<TreeNode> stack = new Stack<>();
        while(!stack.isEmpty() || root != null){
            while(root != null){
                stack.push(root);
                root = root.right;
            }
            TreeNode pop = stack.pop();
            count ++;
            if(count == k)
                return pop.val;
            root = pop.left;
        }
        return -1;
        }
}
```
