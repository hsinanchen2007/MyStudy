### 解析
最早这个题是在计蒜客做到的，算是接触的第一个动归题，这题说白了就是斐波拉契。
到第n阶楼梯有两种走法，一种是从n-1阶跳一格，一种是从n-2阶一次跳两格。
以此类推n-1阶到第1阶，显而易见是斐波拉契公式。

### 代码
```java
class Solution {
    public int climbStairs(int n) {
        int a=1;
        int b=1;
        int c=0;
        for(int i=2;i<n+1;i++){
            c=a+b;
            a=b;
            b=c;
        }
        if(n<2) return 1;
        else return c;
    }
}
```