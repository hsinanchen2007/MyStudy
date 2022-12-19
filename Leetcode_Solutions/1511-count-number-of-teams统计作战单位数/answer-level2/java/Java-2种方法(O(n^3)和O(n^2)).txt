# 代码
```java [-O(n^2)]
class Solution {
    public int numTeams(int[] rating) {
        int len = rating.length, res = 0;
        int[] larger_count = new int[len], smaller_count = new int[len];
        for (int i = 0; i < len; ++i) {
            int base = rating[i];
            for (int j = i + 1; j < len; ++j)
                if (base > rating[j]) ++smaller_count[i];
                else ++larger_count[i];
        }
        for (int i = 0; i < len - 2; ++i) {
            int first = rating[i];
            for (int j = i + 1; j < len - 1; ++j)
                res += first > rating[j] ? smaller_count[j] : larger_count[j];
        }
        return res;
    }
}
```
```java [-O(n^3)]
class Solution {
    public int numTeams(int[] rating) {
        int len = rating.length, res = 0;
        for (int i = 0; i < len - 2; ++i) {
            int first = rating[i];
            for (int j = i + 1; j < len - 1; ++j) {
                int second = rating[j];
                boolean isNextSmaller = first > second;
                for (int k = j + 1; k < len; ++k)
                    if ((second > rating[k]) == isNextSmaller)
                        ++res;
            }
        }
        return res;
    }
}
```