### 思路
可以用动态规划的方法，先求出answer[0]，然后当i >= 1时，且A[index]已经改变：
1. A[index]为偶数，queries[i][0]为偶数：answer[i] = answer[i-1] + queries[i][0]
2. A[index]为偶数，queries[i][0]为奇数：answer[i] = answer[i-1] + A[index]
3. A[index]为奇数，queries[i][0]为偶数：answer[i] = answer[i-1]
4. A[index]为奇数，queries[i][0]为奇数：answer[i] = answer[i-1] - A[index] + queries[i][0]


### 实现
```java
class Solution {
    public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
        int[] answer = new int[queries.length];
        int index = queries[0][1];
        A[index] += queries[0][0];
        for(int j = 0; j < A.length; j++){
            if(A[j] % 2 == 0){
                answer[0] += A[j];
            }
        }
        for(int i = 1; i < queries.length; i++){
            index = queries[i][1];
            A[index] += queries[i][0];
            if(A[index] % 2 == 0 && queries[i][0] % 2 == 0){
                answer[i] = answer[i-1] + queries[i][0];
            }else if(A[index] % 2 == 0 && queries[i][0] % 2 != 0){
                answer[i] = answer[i-1] + A[index];
            }else if(A[index] % 2 != 0 && queries[i][0] % 2 == 0){
                answer[i] = answer[i-1];
            }else{
                answer[i] = answer[i-1] - A[index] + queries[i][0];
            }
        }
        return answer;
    }
}
```
