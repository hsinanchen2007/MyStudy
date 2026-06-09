### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int fib(int n) {
        if(n<0)
            return -1;
        if(n<=1)
            return n;
        int i=2;
        int r1 = 0;
        int r2 = 1;
        while(i<=n){
            int temp = (r1+r2)%1000000007;
            r1 = r2;
            r2 = temp;
            i++;
        }
        return r2;
    }
}
```