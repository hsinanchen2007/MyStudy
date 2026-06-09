### 解题思路
先排序，后逐渐遍历增加！

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        Arrays.sort(A);
        int move = 0;
        int Ai;
        int Ai2;
        for (int i = 0; i < A.length - 1; i++) {
            Ai = A[i];
            Ai2 = A[i + 1];
            if (Ai2 == Ai) {
                A[i + 1]++;
                move++;
            } else if (Ai2 < Ai) {
                int count = Ai - Ai2;
                move += count + 1;
                A[i + 1] += count + 1;
            }
        }

        return move;
    }
}
```