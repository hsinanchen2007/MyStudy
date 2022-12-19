
### 代码

```java
class Solution {
    public int cuttingRope(int n) {
        if(n <= 3) return n-1;
        //取余数
        int mod = (int)1e9 + 7;
        //用long接收数据
        int res = 1;
        while(n > 4){
            res *= 3;
            n -= 3;
        }
        return res * n;
    }
}
```