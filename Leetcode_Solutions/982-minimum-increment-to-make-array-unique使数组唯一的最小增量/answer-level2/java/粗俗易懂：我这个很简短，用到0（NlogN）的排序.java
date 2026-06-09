```
class Solution {
    public int minIncrementForUnique(int[] A) {
        // 第二次优化版本：22ms，主要优化for循环里面的
        int len = A.length;
        Arrays.sort(A);

        int count = 0;
        for (int i = 1; i < len; i++){
            if (A[i-1] >= A[i]){
                int lenNum = A[i-1] - A[i] + 1;
                A[i] += lenNum;
                count += lenNum;
            }
        }

        return count;

        /* 第一次实现方式，1371ms
        int len = A.length;
        Arrays.sort(A);

        int count = 0;
        for (int i = 1; i < len; i++){
            while (A[i-1] >= A[i]){ // 这里其实没必要一次次加，看优化版本
                A[i] += 1;
                count++;
            }
        }

        return count;*/
    }
}
```
