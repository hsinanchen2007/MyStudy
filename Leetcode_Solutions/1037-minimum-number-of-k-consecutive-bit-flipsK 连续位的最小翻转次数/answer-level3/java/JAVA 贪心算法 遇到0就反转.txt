### 解题思路
JAVA 贪心算法 遇到0就反转

### 代码

```java
class Solution {
    public int minKBitFlips(int[] A, int K) {
        int size = A.length;
        int result = 0;
        for (int i = 0; i < size; i++) {
            if (A[i] == 0) {
                if (i + K > size) {
                    return -1;
                } else {
                    for (int j = i; j < i + K; j++) {
                        A[j] ^= 1;
                    }
                    result++;
                }
            }
        }
        return result;
    }
}
```