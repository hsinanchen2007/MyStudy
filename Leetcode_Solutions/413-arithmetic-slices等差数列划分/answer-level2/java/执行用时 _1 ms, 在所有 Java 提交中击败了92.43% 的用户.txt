```
class Solution {
    // 根据两两之间的差值进行判断
    public int numberOfArithmeticSlices(int[] A) {
        if (A.length < 3) return 0;
        int nums = 0;
        
        for (int i = 1; i < A.length; i++) {
            A[i-1] = A[i] - A[i-1];
        }
        int m = 0;
        int n = 0;
        for (int i = 1; i < A.length - 1; i++) {
            if (A[i] == A[i-1]) {
                m++;
                n += m; // 归纳法：f(i) = f(i-1) + (i - 2);f(i):长度为i的等差数组包含的等差数列的总个数
            } else {
                nums += n;
                n = 0;
                m = 0;
            }
        }
        nums += n;
        return nums;
    }
}
```
