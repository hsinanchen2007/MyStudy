### 解题思路
自顶向下的分析，自底向上的求解

### 代码

```java
class Solution {
    public int climbStairs(int n) {
        int sum=0;
        if(n<3) return n;
        int n1=1,n2=2;
        for(int i=3;i<=n;i++){
            sum=n1+n2;
            n1=n2;
            n2=sum;
        }
        return sum;
    }
}
```