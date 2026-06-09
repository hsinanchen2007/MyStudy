### 解题思路
- 使用动态规划，创建一个n+1的数组大小，用于记忆f(n)=f(n-1)+f(n-2);

### 代码

```java
class Solution {
    public int climbStairs(int n) {
        if(n<=2){return n;}
        int [] count = new int[n+1];
        count[1] =1;
        count[2] =2;
        for(int i=3;i<=n;i++){
            count[i] = count[i-1]+count[i-2];
        }
        return  count[n];
    }
}
```