
有三个细节非常重要
1. k取到什么时候返回结果
2. 在calc函数中while loop的循环条件
3. 在calc函数中while loop的steps每次增加多少
### 代码

```java
class Solution {
    public int findKthNumber(int n, int k) {
        int cur = 1;
        k = k - 1;
        while (k > 0) {
            int steps = calc(n, cur, cur + 1);
            if (steps <= k) {
                k -= steps;
                cur ++;
            } else {
                cur *= 10;
                k --;
            }
        }
        return cur;
    }

    public int calc(int n, long n1, long n2) {
        int steps = 0;
        while (n1 <= n) {
            steps += Math.min(n2, n + 1) - n1;
            n2 *= 10;
            n1 *= 10;
        }
        return steps;
    }
}
```