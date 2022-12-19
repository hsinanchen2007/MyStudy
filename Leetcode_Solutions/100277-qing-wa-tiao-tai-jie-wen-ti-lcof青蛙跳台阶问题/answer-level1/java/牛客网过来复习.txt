### 解题思路
就是斐波那契数列

### 代码

```java
class Solution {
    public int numWays(int n) {
        if(n==0||n==1){
            return 1;
        }
        int a=1;
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