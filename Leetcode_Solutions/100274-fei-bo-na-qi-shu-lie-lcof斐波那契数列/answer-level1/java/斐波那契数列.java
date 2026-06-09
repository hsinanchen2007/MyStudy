### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int fib(int n) {
        if(n<2)
        return n;
        int []num=new int[n+1];
        num[0]=0;num[1]=1;
        for(int i=2;i<=n;i++)
        num[i]=(num[i-1]+num[i-2])%1000000007;
        return num[n];
    }
}
```