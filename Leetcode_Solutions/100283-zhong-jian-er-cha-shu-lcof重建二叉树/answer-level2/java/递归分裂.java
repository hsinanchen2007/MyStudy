    //递归：时间复杂度O(n),空间复杂度O(n)
    //先序遍历结果是：根节点，左子树，右子树
    //中序遍历结果是：左子树，根节点，右子树
    //先序遍历第一个就是根节点
    //把它放到中序遍历中：中序遍历分成左右俩子树
    //再根据子树长度，得到先序遍历左右俩子树
    //然后再递归求左右子树
    //由于要在中序遍历中找根节点，就把它放入了哈希表
    
    class Solution {
        private HashMap<Integer,Integer> hashMap = new HashMap<>();
        public TreeNode buildTree(int[] preorder, int[] inorder) {
           int length = inorder.length;
           for(int i = 0; i < length; i++){
               hashMap.put(inorder[i],i);
           }
           return buildTree(preorder,0,preorder.length - 1,inorder, 0 , inorder.length - 1);
        }
        private TreeNode buildTree(int[] preorder, int left, int right, int[] inorder , int left1, int right1){
           if(left > right || left1 > right1){
               return null;
           }
           TreeNode root = new TreeNode(preorder[left]);
           int index = hashMap.get(preorder[left]);
           int leftLength = index - left1;
           int rightLength = right1 - index;
           root.left = buildTree(preorder,left+1, left + leftLength, inorder, left1, index - 1 );
           root.right = buildTree(preorder, left + leftLength + 1, right, inorder, index + 1, right1  );
           return root;
        }
    }

![f8bf7751239b0869da5331e574654d3876f9cd33.jpg@518w_1e_1c.jpg](https://pic.leetcode-cn.com/427a8f1f45300b27022b409d32b0e0764eb5ebacd3bf5691ee24ae272503dd3d-f8bf7751239b0869da5331e574654d3876f9cd33.jpg@518w_1e_1c.jpg)

