### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
        private int location = 0;
        /**
         * 根据一棵树的中序遍历与后序遍历构造二叉树。
         * 你可以假设树中没有重复的元素。
         * */
        public TreeNode buildTree(int[] inorder, int[] postorder) {
            if(inorder == null || postorder == null || inorder.length != postorder.length ||
            inorder.length == 0){
                return null;
            }
            location = inorder.length -1;

            return buildTree(inorder, postorder, 0, location);
        }

        private TreeNode buildTree(int[] inorder, int[] postorder, int postBe, int postEnd){
            if(postBe > postEnd){
                return null;
            }
            TreeNode root = new TreeNode(postorder[location]);
            int i = postBe;
            while(i <= postEnd && inorder[i] != root.val){
                i++;
            }
            location --;
            if(i + 1 < postEnd){
                root.right = buildTree(inorder, postorder, i + 1, postEnd);
            }else if(i + 1 == postEnd){
                root.right = new TreeNode(postorder[location--]);
            }

            if(postBe < i - 1){
                root.left = buildTree(inorder, postorder, postBe, i - 1);
            }else if(postBe == i - 1){
                root.left = new TreeNode(postorder[location--]);
            }

            return root;
        }
    }
```