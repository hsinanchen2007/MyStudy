> 有关更多题解，请访问 Gitee 中的项目【[myleetcode](https://gitee.com/guobinhit/myleetcode)】，欢迎大家共同参与此项目！

>

```
public class _108 {
    public TreeNode sortedArrayToBST(int[] num) {
        if (num.length == 0) return null;
        return helper(num, 0, num.length - 1);
    }

    private TreeNode helper(int[] num, int low, int high) {
        if (low > high) return null;
        int mid = (low + high) / 2;
        TreeNode root = new TreeNode(num[mid]);
        root.left = helper(num, low, mid - 1);
        root.right = helper(num, mid + 1, high);
        return root;
    }
}
```
