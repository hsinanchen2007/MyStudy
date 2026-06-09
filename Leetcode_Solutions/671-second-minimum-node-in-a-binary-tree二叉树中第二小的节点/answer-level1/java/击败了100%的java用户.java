本人建了个公众号用于刷题交流，欢迎关注：
![qrcode_for_gh_8eedbc428c9a_258(1).jpg](https://pic.leetcode-cn.com/e5f794b173fbe256a541447fc7ff8e6eb031774890bdfdb48ca3c7866dc81dc2-qrcode_for_gh_8eedbc428c9a_258\(1\).jpg)


```
public int findSecondMinimumValue(TreeNode root) {
        if (root == null || (root.left == null && root.right == null)) {
            return -1;
        }

        int left = root.left.val;
        int right = root.right.val;

        if (left == root.val) {
            left = findSecondMinimumValue(root.left);
        }

        if (right == root.val) {
            right = findSecondMinimumValue(root.right);
        }

        if (left != -1 && right != -1) {
            return Math.min(left, right);
        }
        if (left != -1) {
            return left;
        }
        return right;

    }
```
