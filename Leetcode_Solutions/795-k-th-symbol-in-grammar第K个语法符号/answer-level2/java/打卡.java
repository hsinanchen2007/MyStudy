### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int kthGrammar(int N, int K) {
        if(N == 1) {
            return 0;
        }
        return helper(N, K);
    }

    public int helper(int N, int K) {
        if(N == 2) {
            return K == 1 ? 0 : 1;
        } else {
            int  half = (int)Math.pow(2, N - 2);
            if(K > half) {
                return helper(N - 1, K - half) == 1 ? 0 : 1;
            } else {
                return helper(N - 1, K);
            }
            
        }
    }
}
```