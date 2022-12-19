
    class Solution {
        public boolean verifyPostorder(int[] postorder) {
            int[] inorder = Arrays.copyOf(postorder, postorder.length);
            Arrays.sort(inorder);  // 升序即为中序遍历
            return dfs(postorder, 0, postorder.length - 1, inorder, 0, inorder.length - 1);
        }

        public boolean dfs(int[] postorder, int i, int j, int[] inorder, int p, int q) {
            if(i >= j) {
                return true;
            }
            int num = postorder[j];
            for(int k = p;k <= q;k++) {
                int ld = k - p;  // 左子树节点个数
                int rd = q - k;  // 右子树节点个数
                if(inorder[k] == num) {
                    if(j - i == 1) {
                        if(k == p) {
                            if(postorder[j] > postorder[i]) {
                                return false;
                            }
                        }else {
                            if(postorder[j] < postorder[i]) {
                                return false;
                            }
                        }
                    }
                    return dfs(postorder, i, i + ld - 1, inorder, p, k - 1) &&  // 左子树
                        dfs(postorder, j - rd, j - 1, inorder, k + 1, q);    // 右子树
                }
            }
            return false;
        }
    }