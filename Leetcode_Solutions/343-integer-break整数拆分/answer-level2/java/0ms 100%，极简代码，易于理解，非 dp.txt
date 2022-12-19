### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int integerBreak(int n) {
        if(n <= 3) return n-1;
        int x = n/3, j = n % 3;
        if(j == 0){
            return (int)Math.pow(3, x);
        } else if(j==2){
            return (int)Math.pow(3, x) * 2;
        } else {
            // j==1
            return (int)Math.pow(3, x-1) * 2 * 2;
        }
    }
}
```