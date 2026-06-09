其实本题思想与斐波那契数列类似
```java []
class Solution {
    public int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int pre,cur;
        int result=0;
        pre=1;cur=2;
        for(int i=3;i<=n;i++){
            result=pre+cur;
            pre=cur;cur=result;
        }
        return result;
    }
}
```
