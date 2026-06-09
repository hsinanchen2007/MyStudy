### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
     public int climbStairs(int n) {
         if (n==1) return 1;
        if (n==2) return 2;
        int[] f = new int[n];
        f[0] = 1;
        f[1] = 2;
        for (int i=2;i<n;i++){
            f[i] = f[i-1] + f[i-2];
        }
        return f[n-1];
    }
}
```