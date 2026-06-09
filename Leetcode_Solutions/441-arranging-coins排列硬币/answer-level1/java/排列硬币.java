### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int arrangeCoins(int n) {
        long i = 1;
        long sum = 0;
        int ans = 0;
        while(sum <= n){
            sum = sum + i;
            i = i + 1;
            
            if(sum <= n)    
                ans = ans + 1;
        }
        return ans;
    }
}
```