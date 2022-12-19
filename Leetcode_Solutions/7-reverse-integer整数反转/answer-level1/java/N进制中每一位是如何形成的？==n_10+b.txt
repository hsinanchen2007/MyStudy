### 解题思路
此处撰写解题思路
`n = n*10 + x%10;`
### 代码

```java
class Solution {
    public int reverse(int x) {
        long n = 0;
        while(x != 0) {
            n = n*10 + x%10;
            x = x/10;
        }
        return (int)n==n? (int)n:0;

    }
}
```