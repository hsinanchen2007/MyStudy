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
        public TreeNode buildTree(int[] preorder, int[] inorder) {
            if(inorder == null || preorder == null || inorder.length != preorder.length ||
            inorder.length == 0){
                return null;
            }

            return buildTree(preorder, inorder, 0, preorder.length - 1 );
        }

        private TreeNode buildTree(int[] preorder, int[] inorder, int postBe, int postEnd){
            if(postBe > postEnd){
                return null;
            }
            TreeNode root = new TreeNode(preorder[location]);
            int i = postBe;
            while(i <= postEnd && inorder[i] != root.val){
                i++;
            }
            location ++;
            if(postBe < i - 1){
                root.left = buildTree(preorder,inorder,  postBe, i - 1);
            }else if(postBe == i - 1){
                root.left = new TreeNode(preorder[location++]);
            }

            if(i + 1 < postEnd){
                root.right = buildTree(preorder,inorder,  i + 1, postEnd);
            }else if(i + 1 == postEnd){
                root.right = new TreeNode(preorder[location++]);
            }

            return root;
        }
    }
```