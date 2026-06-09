思路很简单结合剪枝
```
    class BSTIterator {

        private Stack<TreeNode> stack=new Stack<>();
        public BSTIterator(TreeNode root) {
            if(root!=null){
                stack.push(root);
            }
        }

        /**
         * @return the next smallest number
         */
        public int next() {
            TreeNode curNode=stack.pop();
            while (curNode.left!=null){
                /*剪枝*/
                TreeNode temp=curNode.left;
                curNode.left=null;
                stack.push(curNode);
                curNode=temp;
            }
            if(curNode.right!=null){
                stack.push(curNode.right);
            }
            return curNode.val;
        }

        /**
         * @return whether we have a next smallest number
         */
        public boolean hasNext() {
            return stack.size()!=0;
        }
    }
```
