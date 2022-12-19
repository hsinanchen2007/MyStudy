### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numWays(int n) {
        long curr = 0, next = 1, sum = 0;

        for(int k = 0;k<n;k++)
        {
            sum = (curr+next)%1000000007;
            curr = next;
            next = sum;
        }
        return (int)next;        
    }
}
```