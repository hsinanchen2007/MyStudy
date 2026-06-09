### 解题思路
第一个思路：是想要将原来的A数组扩大成B数组(0AA),然后再这个新数组里寻找长度小于A.length的最大字串和。但是超时了。核心思想：A==>两个数组A拼接再在前面加0：B(0AA)==>求新数组B的求和数组S，则A(n,m]区间求和=S(m)-S(n);其中0<m-n<=A.length.

### 代码
```java
class Solution {
    public int maxSubarraySumCircular(int[] A) {
        int len = 2 * A.length + 1;
        int[] B = new int[len];
        int[] S = new int[len];

        B[0] = 0;
        S[0] = 0;
        for (int i = 0; i < len - 1; i++) {
            B[i + 1] = A[i % A.length];
            S[i + 1] = S[i] + B[i + 1];
        }
        System.out.println("S:" + Arrays.toString(S));

        int max = A[0];
        for (int m = 1; m < len; m++) {
            for (int n = 0; n < m; n++) {
                if (m - n < A.length + 1) {
                    int res = S[m] - S[n];
                    if (res > max) {
                        max = res;
                    }
                }
            }
        }
        return max;
```


### 解题思路
第二个思路：求解两个kadana算法问题。先求A数组最大值max和总和sum，然后再求去掉A[0]和A[A.length-1]元素后的A数组的最小值min，最后求max和(sum-min)的最大值
### 代码

```java
class Solution {
    public int maxSubarraySumCircular(int[] A) {
        int sum = A[0];
        int max = A[0];
        int dp = A[0];
        for (int i = 1; i < A.length; i++) {
            sum += A[i];
            if (dp >0) {
                dp += A[i];
            } else{
                dp = A[i];
            }
            max = Math.max(dp,max);
        }
        if (A.length < 3){
            return max;
        }

        int min = A[1];
        int dpMin = A[1];
        for (int j = 2; j < A.length-1; j++) {
            if (dpMin < 0) {
                dpMin += A[j];
            } else {
                dpMin = A[j];
            }
            min = Math.min(dpMin, min);
        }

        return Math.max(max,(sum-min));
    }
}
```