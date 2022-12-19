### 代码

```java
class Solution {
    public int bagOfTokensScore(int[] tokens, int P) {
        Arrays.sort(tokens);
        int count = 0;
        if (tokens.length == 0 || P < tokens[0]) {
            return count;
        }
        boolean ismax = true;//判断最后出循环的时候是否加上右侧指针
        int cur = 0;
        int max = tokens.length - 1;
        while (cur <= max) {
            if (P >= tokens[cur]) {
                P -= tokens[cur];
                cur++;
                count++;
                ismax = false;
            } else {
                P += tokens[max];
                count--;
                max--;
                ismax = true;
            }
        }
        return ismax ? count + 1 : count;
    }
}
```