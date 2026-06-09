### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
     public int minIncrementForUnique(int[] A) {
        if (A.length == 0) {
            return 0;
        }
        Arrays.sort(A);
        int[] ints = new int[80000];
        int result = 0;
        for (int i = 0; i < A.length; ++i) {
            if (ints[A[i]] == 1) {
                for (int j = 1; ; ++j) {
                    int value1 = A[i] + j;
                    if (ints[value1] == 0) {
                        ints[value1] = 1;
                        result += j;
                        break;
                    }
                }
            } else {
                ints[A[i]] = 1;
            }
        }
        return result;
    }
}
```