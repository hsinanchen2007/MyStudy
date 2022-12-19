```
public class LeetCode1052 {
    /**
     * 思路：滑动窗口
     * 实现：参考思路
     * 算法复杂度：O(N)
     * 空间复杂度：O(N)
     * @param customers
     * @param grumpy
     * @param X
     * @return
     */
    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int sum = 0;
        int len = grumpy.length;
        int tmpSum = 0;
        for (int cindex = 0; cindex < customers.length; cindex++) {
            if (cindex < X) {
                tmpSum += customers[cindex];
            } else {
                tmpSum += customers[cindex] * (1-grumpy[cindex]);
            }
        }
        sum = Math.max(sum, tmpSum);
        for (int i = X; i < len; i++) {
            //如果 grumpy[i - X] == 1，则减去该元素，如果为 0，则不减，
            //如果 grumpy[i] == 1，则增加该元素，如果为 0，则不加
            tmpSum = tmpSum + customers[i] * grumpy[i] - customers[i - X] * grumpy[i - X];
            sum = Math.max(sum, tmpSum);
        }
        return sum;
    }
}
```
