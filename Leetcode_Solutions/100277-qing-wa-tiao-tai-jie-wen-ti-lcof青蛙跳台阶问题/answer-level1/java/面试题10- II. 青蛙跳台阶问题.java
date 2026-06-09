### 解题思路
此题思路基本与斐波那契数列相同。
因为青蛙一次只能跳1阶或者2阶，所以最后一步一定是从n-1级台阶或者n-2级台阶跳上来的。于是，跳上n级台阶的跳法就是跳上n-1级台阶的跳法加上跳上n-2级台阶的跳法。
f(n)=f(n-1)+f(n-2)

吐槽一下：0级台阶的时候为什么会返回1？不该是0吗。。。

### 代码

```java
class Solution {
    public int numWays(int n) {
        if(n==0||n==1){
            return 1;
        }

        int a=1,b=1;
        int sum=0;
        for(int i=2;i<=n;i++){
            sum=(a+b)%1000000007;
            a=b;
            b=sum;
        }
        return sum;
    }
}
```