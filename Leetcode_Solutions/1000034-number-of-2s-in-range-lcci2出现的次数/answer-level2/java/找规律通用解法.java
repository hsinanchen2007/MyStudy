### 解题思路
分析每一位上出现数字2的次数，一位一位的遍历求和。每一位数字2出现的次数由其高位、低位共同决定的。

### 代码

```java
class Solution {
    public int numberOf2sInRange(int n) {
         long res = 0;


        for(long k = 1; k <=n; k=10*k){
            long high = n/(10*k);
            long low = n%k;
            long cur = (n/k)%10;
            if(cur < 2){
                res  = res + high*k;
            }else if(cur == 2){
                res = res + low + 1 + high*k;
            }else{
                res = res + (high+1)*k;
            }
        }

        return (int)res;
    }
}
```