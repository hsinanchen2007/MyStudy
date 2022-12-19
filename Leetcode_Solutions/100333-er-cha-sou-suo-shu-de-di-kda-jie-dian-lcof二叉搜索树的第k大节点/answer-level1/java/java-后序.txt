```
class Solution {
    int cnt = 0;
    int result = 0;
    public int kthLargest(TreeNode root, int k) {
        if(root == null || cnt >= k) {
            return result;
        }
        kthLargest(root.right, k);
        cnt++;
        result = (cnt == k) ? root.val: result;
        kthLargest(root.left, k);
        return result;
    }
}
```
