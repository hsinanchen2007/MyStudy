![image.png](https://pic.leetcode-cn.com/9d52eab9055f9c68ece214ecfe0bcc910d5ffa435dd8f3cfc7b63cc86515ca0d-image.png)
 利用数组将每个节点存入数组中， 当前节点的值与数组中的每个值相减，与最小的值比较。
```
class Solution {
    int min = Integer.MAX_VALUE;
    int[] arr = new int[100];
    int p = 0;
    public int minDiffInBST(TreeNode root) {
        if (root == null) {
            return 0;
        }
        arr[p] = root.val;
        for (int i = p - 1; i >= 0; i--) {
            min = Math.min(min, Math.abs(arr[p] - arr[i]));
        }
        p++;
        minDiffInBST(root.left);
        minDiffInBST(root.right);
        return min;
    }  
}
```
