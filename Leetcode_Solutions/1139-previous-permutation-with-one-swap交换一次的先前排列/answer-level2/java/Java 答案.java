```
public class Solution {
    public int[] prevPermOpt1(int[] A) {
        // 从最后面开始，如果要换，一定要找一个，小于他的最大数，来换。
        for (int i = A.length - 1; i >= 0; i --) {
            // 保证不越界
            if (i + 1 < A.length) {
                int tempMax = -1; // 因为 A[i] 均大于0
                int tempIndex = -1;
                for (int j = i; j < A.length; j ++) {
                    if (A[j] < A[i] && tempMax < A[j]) {
                        tempMax = A[j];
                        tempIndex = j;
                    }
                }
                if (tempMax != -1) {
                    //找到一个可替换方案
                    int temp = A[i];
                    A[i] = A[tempIndex];
                    A[tempIndex] = temp;
                    return A;
                }
            }
            // 越界，啥都不做。
        }
        return A;
    }
}
```
