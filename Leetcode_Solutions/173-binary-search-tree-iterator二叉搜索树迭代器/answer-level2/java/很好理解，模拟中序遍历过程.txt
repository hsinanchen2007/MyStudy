```
class BSTIterator {
        private TreeNode curr;
        private Stack<TreeNode> stack = new Stack<>();

        public BSTIterator(TreeNode root) {
            this.curr = root;
        }

        /** @return the next smallest number */
        public int next() {
            while(curr!=null){
                stack.push(curr);
                curr = curr.left;
            }
            curr = stack.pop();
            int val = curr.val;
            curr = curr.right;
            return val;
        }

        /** @return whether we have a next smallest number */
        public boolean hasNext() {
            if(stack.isEmpty()&&curr==null) return false;
            return true;
        }
    }
```
