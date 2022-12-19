### 解题思路
动态规划自底向上求解，每一步%1000000007即可

### 代码

```java
class Solution {
    public int fib(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int a=0;
        int b=1;
        int sum=0;
        for(int i=2;i<=n;i++){
            sum=a%1000000007+b%1000000007;
            a=b%1000000007;
            b=sum%1000000007;
        }
        return sum%1000000007;
    }
}
```