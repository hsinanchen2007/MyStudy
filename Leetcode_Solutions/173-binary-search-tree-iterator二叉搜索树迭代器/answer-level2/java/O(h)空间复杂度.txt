之前面Google背靠背第二轮的时候被问了一个设计类问题，当时真的一脸懵逼。虽然找到了intern但是还是觉得需要多刷一下设计类问题。
这个问题如果没有空间复杂度O(h)这个要求其实非常简单，遍历一遍存在list里就行。因为有空间复杂度要求，所以使用了stack，下面是代码。
```
class BSTIterator {

        Stack<TreeNode> stack = new Stack<>();
        public BSTIterator(TreeNode root) {
            while(root!=null){
                stack.push(root);
                root = root.left;
            }
        }

        /** @return the next smallest number */
        public int next() {
            TreeNode node = stack.pop();
            if(node.right!=null){
                TreeNode temp = node.right;
                while(temp!=null){
                    stack.push(temp);
                    temp = temp.left;
                }
            }
            return node.val;
        }

        /** @return whether we have a next smallest number */
        public boolean hasNext() {
            if(stack.isEmpty()){
                return false;
            }
            else{
                return true;
            }
        }

    }
```
