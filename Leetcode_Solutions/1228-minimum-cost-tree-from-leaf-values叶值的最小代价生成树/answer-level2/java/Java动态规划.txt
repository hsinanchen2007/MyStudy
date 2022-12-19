- 回忆中序序列，对于序列中的某一个元素，它左边的全部元素在这个元素的左子树中，它右边的全部元素在这个元素的右子树中。
- 根据题意，给出的中序序列的**所有元素都是叶节点**。我们可以隐含地将序列分为左右两边，左半部分是左子树，右半部分是右子树。
- 我们可以递归地求解最小和，即定义一个方法**getMinSum**，让它返回可以得到的最小和。因为我们将序列分为左右两边，它们分别是左右子树，所以只要在两边分别找出最大元素就可以计算当前节点的值。
- 为了避免重复计算，设置备忘录记录一定范围内序列可能得到的最小和。
```
class Solution {

    public int mctFromLeafValues(int[] arr) {
        if (arr == null || arr.length == 0)
            return 0;
        int n = arr.length;
        memoization = new int[n][n];
        return getMinSum(arr, 0, arr.length - 1);
    }

    private int[][] memoization;

    private int getMinSum(int[] arr, int left, int right) {
        if (left == right) {
            return 0;
        }
        if (memoization[left][right] != 0)
            return memoization[left][right];
        int minSum = Integer.MAX_VALUE;
        for (int i = left; i < right; i++) {
            int leftStart = left, leftEnd = i, rightStart = i + 1, rightEnd = right;
            int temp = getMinSum(arr, leftStart, leftEnd) + getMinSum(arr, rightStart, rightEnd) +
                    getMaxNum(arr, leftStart, leftEnd) * getMaxNum(arr, rightStart, rightEnd);
            minSum = Math.min(temp, minSum);
        }
        memoization[left][right] = minSum;
        return minSum;
    }

    private int getMaxNum(int[] arr, int left, int right) {
        int max = Integer.MIN_VALUE;
        for (int i = left; i <= right; i++) {
            max = Math.max(max, arr[i]);
        }
        return max;
    }
}
```
