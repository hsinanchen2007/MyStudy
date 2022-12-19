### 关键点就是这一行：
***long res = 1;***
一定要申请为long
### 代码

```java
class Solution {
    public int cuttingRope(int n) {
        if(n == 2){
            return 1;
        }
        if(n == 3){
            return 2;
        }
        //n==4 2*2 = 4
        //余数一定为 若干个3以及1个1或者2个2
        long res = 1;
        while(n > 4){
            res *= 3;
            n -= 3;
            res %= (1e9+7);
        }
        System.out.println(res);
        System.out.println(n);
        res = (int)(res * n % (1e9+7));
        return (int)res;
    }
}
```