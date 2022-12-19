### 解题思路
根据官方题解的思路加上自己的思路，排除了一些不必要的遍历，但是效率还是没提高很明显。

### 代码

```java
class Solution {
    public String largestTimeFromDigits(int[] A) {
        
        int ans = -1;
        for (int i = 0; i < 4; ++i) {
            if (A[i] < 3) {
                for (int j = 0; j < 4; ++j) {
                    if (i != j) {
                        if (A[i] == 2 && A[j] > 3) {
                            continue;
                        }
                        for (int k = 0; k < 4; ++k) {
                            if (A[k] < 6) {
                                if (i != j && j != k && i != k) {
                                    int l = 6 - i - j - k;
                                    int hours = 10 * A[i] + A[j];
                                    int mins = 10 * A[k] + A[l];
                                    if (hours < 24 && mins < 60) {
                                        ans = Math.max(ans, 60 * hours + mins);
                                    }
                                }
                            }
                            
                        }
                    }
                }
            }
            
        }

        return ans >= 0 ? String.format("%02d:%02d", ans / 60, ans % 60) : "";
    }
}
```