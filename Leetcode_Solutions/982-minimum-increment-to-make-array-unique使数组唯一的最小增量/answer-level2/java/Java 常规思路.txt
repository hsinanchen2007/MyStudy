### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        if (null == A || 1 >= A.length)
            return 0;

        Arrays.sort(A);
        showArr(A);

        int cnt = 0;
        int before = A[0];

        for (int i=1; i<A.length; ++i) {
            if (A[i] <= before) {
                cnt += before + 1 - A[i];
                A[i] = before+1;
            }
            before = A[i];
        }
        return cnt;
    }

    void showArr(int[] a) {
        for (int n: a)
            System.out.print(n + " ");
    }

}
```