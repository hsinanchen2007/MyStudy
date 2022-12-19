### 解题思路
1. 中心扩展法。

### 代码

```java
class Solution {
    public int countSubstrings(String S) {
        int N = S.length(), res = 0;
        for (int center = 0; center <= 2*N-1; ++center) {
            int left = center / 2;
            int right = left + center % 2;
            while (left >= 0 && right < N && S.charAt(left) == S.charAt(right)) {
                res++;
                left--;
                right++;
            }
        }
        return res;
    }
}

```