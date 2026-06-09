### 解题思路
总的思路就是要尽可能减少计算
### 代码

```java
class Solution {
    public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
 
        int len = queries.length, evenSum = 0;
        int[] answer = new int[len];

        for(int a : A) 
            if(a % 2 == 0) 
                evenSum += a; // 6

        for(int i = 0; i < len; i++){
            int val = queries[i][0], index = queries[i][1];

            if(A[index] % 2 == 0)
                evenSum -= A[index];

            A[index] += val;

            if(A[index] % 2 == 0)
                evenSum += A[index];

            answer[i] = evenSum;
        }
        return answer;
    }
}
```