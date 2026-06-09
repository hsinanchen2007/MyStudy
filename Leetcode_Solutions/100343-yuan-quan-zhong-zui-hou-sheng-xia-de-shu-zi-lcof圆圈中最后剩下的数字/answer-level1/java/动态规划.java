### 解题思路
f(n,m)=(f(n-1,m)+m)%n

### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
        if(n<1){
            return 0;
        }
        return (m+lastRemaining(n-1,m))%n;
    }
}
```
```java
class Solution {
    public int lastRemaining(int n, int m) {
        int result=0;
        for(int i=2;i<=n;i++){
            result=(m+result)%i;
        }
        return result;
    }
}
```