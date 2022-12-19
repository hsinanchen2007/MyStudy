### 解题思路
注意判断溢出的条件

### 代码

```java
class Solution {
    public int reverse(int x) {
        int ans = 0;
        int p = 0;
        while(x != 0){
            p = x%10;
            x = x/10;
            if(ans > Integer.MAX_VALUE/10 || (ans == Integer.MAX_VALUE/10 && p == Integer.MAX_VALUE%10))
                return 0;
            else if(ans < Integer.MIN_VALUE/10 || (ans == Integer.MIN_VALUE/10 && p == Integer.MIN_VALUE%10))
                return 0;
            ans = ans*10 + p;
        }
        return ans;
    }
}
```