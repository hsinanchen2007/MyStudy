### 解题思路
迭代解决。

### 代码

```java
class Solution {
    public int numWays(int n) {
        if(n<2){
            return 1;
        }
        int f1 = 1;
        int f2 = 1;
        int res = 0;
        while(n > 1){
            res = (f1+f2)%1000000007;
            f1 = f2;
            f2 = res;
            --n;
        }
        return res;
    }
}
```