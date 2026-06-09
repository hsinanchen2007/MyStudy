```
class Solution {
    public int largestSumAfterKNegations(int[] A, int K) {
        // 快速排序，n*Log(n)
        Arrays.sort(A);
        int result = 0;
        int minMinusNum = 0;
        for (int i : A) {
            if (K > 0) {
                // 如果i=0，并且之后的数都是正数，那么就可以反复加减这个0，对最后的结果没有任何影响
                if (i == 0) {
                    K = 0;
                } else if (i < 0) {
                    // 在到达正数前记录最接近 0 的负数
                    minMinusNum = i;
                    result -= i;
                    K--;
                } else { // 轮到正数了
                    if (minMinusNum == 0) {
                        result -= i * (K % 2);
                        K = 0;
                        continue;
                    }
                    result += i - Math.min(i, -minMinusNum) * (K % 2 == 0 ? 0 : 2);
                    K = 0;
                }
            } else {
                result += i;
            }
        }
        return result;
    }
}
```
