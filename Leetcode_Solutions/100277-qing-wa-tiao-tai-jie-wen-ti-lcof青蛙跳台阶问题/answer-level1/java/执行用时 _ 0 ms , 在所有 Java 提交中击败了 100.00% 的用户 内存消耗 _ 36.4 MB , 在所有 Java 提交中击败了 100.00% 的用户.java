### 解题思路
不知道和面试题9又啥区别。。。

### 代码

```java
class Solution {
    public int numWays(int n) {
        if(n==0){
            return 1;
        }
        if(n==2 || n==1){
            return n;
        }
        int[] results = new int[n+1];
        results[1] = 1;
        results[2] = 2;
        for(int i=3;i<=n;i++){
            results[i] = (results[i-1]+results[i-2])%1000000007;
        }
        return results[n]%1000000007;
    }
}
```