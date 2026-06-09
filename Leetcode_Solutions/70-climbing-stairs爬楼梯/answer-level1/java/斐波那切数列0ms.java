### 解题思路
ways[n]=ways[n-1]+ways[n-2];
即n的方法数等于n-1的方法数加上n-2的方法数。
### 代码

```java
class Solution {
    public int climbStairs(int n) {
        
        if(n==1||n==2||n==3)return n;
        int[] fibles=new int[n+1];
        fibles[1]=1;fibles[2]=2;fibles[3]=3;
        for(int i=4;i<=n;i++)
        {
            fibles[i]=fibles[i-1]+fibles[i-2];
        }
        return fibles[n];
    }
}
```