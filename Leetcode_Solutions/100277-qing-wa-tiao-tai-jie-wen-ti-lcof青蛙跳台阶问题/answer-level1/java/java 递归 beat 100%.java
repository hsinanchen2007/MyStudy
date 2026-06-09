### 解题思路
跳1级台阶1种跳法， 2级台阶2种跳法，n级台阶跳法= 跳到n-1级台阶跳法+ 跳到n-2级台阶跳法。
边界：n<2时有1种跳法
n>=2时进行一个从1到n的循环

### 代码

```java
class Solution {
    public int numWays(int n) {
        //f(n) = f(n-1)+f(n-2);
        if(n<2) return 1;
        int f=0, pre1=1, pre2=1;
        for(int i =1; i<n; i++){
            f = (pre1+pre2)%1000000007;
            pre1 = pre2;
            pre2 = f;
        }
        return f;

    }
}
```