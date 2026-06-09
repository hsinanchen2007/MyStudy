### 解题思路
主要就是搞了一个超值判断, 如果乘以2就超过mod, 那么就把乘3分解成一次乘2mod和一次加单倍的mod

### 代码

```java
class Solution {
    public int cuttingRope(int n) {
        if(n<4) return n-1;

        int result = 1;
        int mod = 1000000007;

        while(n>4){
            if(result*2>mod){
                int temp = result;
                result=temp*2-mod;
                result+=temp;
            }else{
                result*=3;
            }
            result%=mod;
            n-=3;
        }

        int temp = result;
        result=(2*temp)%mod;
        result+=((n-2)*temp)%mod;

        return result%mod;
    }
}
```