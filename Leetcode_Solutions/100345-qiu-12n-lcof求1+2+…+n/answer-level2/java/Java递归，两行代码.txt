时间空间双百

```java
class Solution{
    public int sumNums(int n){
        if(n==1) return 1;
        return n + sumNums(n-1);
    }
}
```
