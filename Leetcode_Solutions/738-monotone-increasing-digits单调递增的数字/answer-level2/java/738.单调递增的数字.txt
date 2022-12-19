### 解题思路
从右往左构造数据，如果a[i]>a[i-1]，说明此时不满足递增，a[i-1]要减1，为了保证目前是最大，a[i]之后的都可以变为9。之后还要接着向前判断。考虑332，第一次变为329，第二次变为299。

### 代码

```java
class Solution {
    public int monotoneIncreasingDigits(int N) {
        
        int[] x = new int[20];
        int len = 0;
        while (N > 0){
            x[len ++] = N % 10;
            N /= 10;
        }
        len --;

        int pos = -1;
        for (int i = 0; i <= len - 1; i ++){
            if (x[i] < x[i + 1]){
                pos = i; // i之前的都要变成9
                x[i + 1] = x[i + 1] - 1; // i+1处要-1
            }
        }

        int ans = 0;
        for (int i = len; i > pos; i --){
            ans = ans * 10 + x[i];
        }
        for (int i = pos; i >= 0; i --){
            ans = ans * 10 + 9;
        }

        return ans;

    }
}
```