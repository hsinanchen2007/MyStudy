### 解题思路
坑爹的题

### 代码

```java
class Solution {
    public int cuttingRope(int n) {
        if(n==2){
            return 1;
        }
        if(n==3){
            return 2;
        }
        if(n==4){
            return 4;
        }
        long result = 1;
        while(n>4){
            result*=3;
            n-=3;
            result = result%1000000007;
        }
        return (int)(result*n%1000000007);
    }
}
```