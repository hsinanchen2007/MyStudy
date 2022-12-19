![image.png](https://pic.leetcode-cn.com/d84e7d7fdb541a17f8f1a08490b3de90c7de75f5c00b46ab5f08837a2a95c771-image.png)

```
class Solution {
    public int[] sortedSquares(int[] A) {
        int[] answer;
        int i, j, k;

        answer = new int[A.length];
        i = 0;
        j = A.length - 1;
        k = A.length - 1;
        while(i <= j){
            if(A[i] * A[i] > A[j] * A[j]){
                answer[k--] = A[i] * A[i];
                i++;
            }else{
                answer[k--] = A[j] * A[j];
                j--;
            }
        }
        return answer;
    }
}
```
