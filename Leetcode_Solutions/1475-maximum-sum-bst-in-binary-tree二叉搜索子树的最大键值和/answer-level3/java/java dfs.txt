### 思路
使用dfs求解，遍历二叉树的每个节点，同时，dfs函数的返回值是一个包含四个元素`(sum, min, max, isBst)`的对象。在遍历过程中不断更新二叉搜索树的`sum`的最大值即可。这里重要的是如何判断以某一节点为`root`的子树是一颗二叉搜索树。需要满足以下几个要求：
1. 左子树和右子树都是一颗二叉搜索树(注意，左右子树为空也算)；
2. 左子树的最大值要小于当前节点值；
3. 右子树的最小值要大于当前节点值。
<br>

```java
class Result {
        int sum;
        int min;
        int max;
        boolean isBst;
        Result(int sum, int min, int max, boolean isBst) {
            this.sum = sum;
            this.min = min;
            this.max = max;
            this.isBst = isBst;
        }
    }

    private int ansMaxSum = 0;

    private Result dfs(TreeNode root) {
        if (root == null) {
            return null;
        }

        Result leftRes = dfs(root.left);
        Result rightRes = dfs(root.right);
        int resSum = root.val;
        int resMin = root.val;
        int resMax = root.val;
        boolean resIsBst = true;

        if (leftRes != null) {
            resSum += leftRes.sum;
            resMin = Math.min(resMin, leftRes.min);
            resMax = Math.max(resMax, leftRes.max);
            resIsBst = leftRes.isBst && leftRes.max < root.val;
        }

        if (rightRes != null) {
            resSum += rightRes.sum;
            resMin = Math.min(resMin, rightRes.min);
            resMax = Math.max(resMax, rightRes.max);
            resIsBst = resIsBst && rightRes.isBst && rightRes.min > root.val;
        }

        if (resIsBst) {
            ansMaxSum = Math.max(ansMaxSum, resSum);
        }

        return new Result(resSum, resMin, resMax, resIsBst);
    }

    public int maxSumBST(TreeNode root) {
        dfs(root);
        return ansMaxSum;
    }
```