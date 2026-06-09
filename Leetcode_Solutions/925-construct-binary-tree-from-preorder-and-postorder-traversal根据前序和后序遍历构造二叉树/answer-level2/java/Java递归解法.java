```
class Solution {
    public TreeNode constructFromPrePost(int[] pre, int[] post) {
        if (pre == null || pre.length == 0 || post == null || post.length == 0) {
            return null;
        }
        TreeNode rootNode = new TreeNode(pre[0]);
        if (pre.length == 1 || post.length == 1) {
            return rootNode;
        }

        int index = getPostIndex(post, pre[1]);
        int[] postLeftArr = Arrays.copyOfRange(post, 0, index + 1);
        int[] postRightArr = Arrays.copyOfRange(post, index + 1, post.length - 1);
        int[] preLeftArr = Arrays.copyOfRange(pre, 1, index + 2);
        int[] preRightArr = Arrays.copyOfRange(pre, index + 2, pre.length);
        rootNode.left = constructFromPrePost(preLeftArr, postLeftArr);
        rootNode.right = constructFromPrePost(preRightArr, postRightArr);
        return rootNode;
    }

    private int getPostIndex(int[] post, int key) {
        for (int i = 0; i < post.length; i++) {
            if (post[i] == key) {
                return i;
            }
        }
        return -1;
    }
}
```
