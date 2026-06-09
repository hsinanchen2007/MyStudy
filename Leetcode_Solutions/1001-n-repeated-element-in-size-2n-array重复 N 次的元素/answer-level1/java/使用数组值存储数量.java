```
class Solution {
    public int repeatedNTimes(int[] A) {
        int[] m = new int[10000];
        int num;
        for (int i = 0; i < A.length; i++) {
            num = A[i];
            m[num]++;
            if (m[num] > 1) {
                return num;
            }
        }
        return 0;
    }
}
```
题目有提示

1. 4 <= A.length <= 10000

2. __.0 <= A[i] < 10000__

3. A.length 为偶数

多提交几次时间和内存使用还不一样,最短的是2ms