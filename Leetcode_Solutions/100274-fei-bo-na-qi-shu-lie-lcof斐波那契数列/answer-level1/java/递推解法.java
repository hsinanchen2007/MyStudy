### 解题思路
先用递归的解法和用数组保存状态的解法都超时了。
用递推发现可以通过

### 代码

```java
class Solution {
    public int fib(int n) {
        if(n <= 1){
            return n;
        }
        int f0 = 0;
        int f1 = 1;
        int sum = 0;
        for(int i = 2 ; i <= n; i ++){
            sum = (f0 + f1)%1000000007;
            f0 = f1;
            f1 = sum;
        }
        return sum%1000000007;

    }
}
```