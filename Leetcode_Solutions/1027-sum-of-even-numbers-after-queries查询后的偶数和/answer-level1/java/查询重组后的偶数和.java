### 解题思路
1. 奇偶判断
2. 避免重复的求和

### 代码

```java
class Solution {
    public int[] sumEvenAfterQueries(int[] a, int[][] queries) {
        int aSum = 0;
        for(int i = 0; i<a.length; i++) {
            if((a[i] & 1) == 0) {
                aSum += a[i];
            }
        }
        int[] answer = new int[a.length];
        int answerIdx = 0;
        for(int i=0; i<queries.length; i++) {
            int val = queries[i][0];
            int idx = queries[i][1];

            if((a[idx] & 1) == 0) {
                if((val & 1) == 0 ) {
                    aSum += val;
                } else {
                    aSum -= a[idx];
                }
            } else {
                if((val & 1) == 1 ) {
                    aSum += a[idx];
                    aSum += val;
                }
            }
            answer[answerIdx++] = aSum;
            a[idx] += val;
        }
        return answer;
    }
}
```