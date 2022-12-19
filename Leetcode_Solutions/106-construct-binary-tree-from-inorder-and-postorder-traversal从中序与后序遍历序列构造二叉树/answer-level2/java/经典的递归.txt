### 解题思路
思路什么就不说了，说一下值得注意的地方。
1. 代码中数组的下标有可能有越界风险
2. 为了避免1中的问题，计算时，没有直接去寻找某个元素的下标，而是计算左右子树的长度，并将其转换为下标的变化

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return buildTree(inorder,0,inorder.length-1,postorder,0,postorder.length-1);
    }

    private TreeNode buildTree(int[] in,int i,int j,int[] post,int m,int n){
        if (i > j)
            return null;
        if (i == j)
            return new TreeNode(in[i]);
        TreeNode root = new TreeNode(post[n]);
        int index_in = findIndex(in, root.val, i, j);
        int left_len = index_in - i;
        int right_len = j - index_in;
        root.left = buildTree(in,i,index_in-1,post,m,m+left_len-1);
        root.right = buildTree(in,index_in+1,j,post,n-right_len,n-1);
        return root;
    }

    private int findValIndex(int[] num, int val) {
        for (int i = 0; i < num.length; i++) {
            if (num[i] == val)
                return i;
        }
        return -1;
    }

    private int findIndex(int[] num,int val,int i,int j){
        for(int k = i; k <= j; k++){
            if (num[k] == val)
                return k;
        }
        return -1;
    }
}
```