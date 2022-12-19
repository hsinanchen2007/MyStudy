### 解题思路
用了两个for循环一直提示我超出时间限制，话说题目在哪里能看到这个要求啊，最后用了从和里面相减的方法才通过orz

### 代码

```java
class Solution {
    public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
       int[] ans = new int[queries.length];
        int sum=0;
        for (int i = 0; i < A.length; i++) {
            if(A[i]%2==0){
                sum+=A[i];
            }
        }
            for (int j = 0; j < queries.length; j++) {

                int k = A[queries[j][1]];
                if (k % 2 == 0) {
                    k += queries[j][0];
                    A[queries[j][1]]+=queries[j][0];
                    if (k % 2 == 0) {
                        sum+= queries[j][0];
                    } else {
                        sum -= k - queries[j][0];
                    }
                } else {
                    k += queries[j][0];
                    A[queries[j][1]]+=queries[j][0];
                        if (k % 2 == 0) {
                            sum +=k;
                    }
                }
                ans[j]=sum;
            }
        return ans;
    }
}
```