### 解题思路

通过迭代

### 代码

```java
class Solution {
    public int climbStairs(int n) {
        if(n==1||n==2){
            return n;
        }
        int one = 2;
        int two = 1;
        int sum = 0;
        for(int i=3;i<=n;i++){
            sum = one+two;
            two = one;
            one = sum;
        }
        return sum;
    }
}
```