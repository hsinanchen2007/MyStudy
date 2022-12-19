### 解题思路
此处撰写解题思路
核心 判断是否超出证书边界 利用了逆向运算的思路。 因为当超出整数最大值之后，其会变成负数，这样逆运算之后和原值肯定不想等。（负数会变成整数）。
### 代码

```java
class Solution {
    public int reverse(int x) {
        int rev = 0;
        while(x != 0){
            int newRev = rev*10 + x%10;
            if((newRev - (x%10))/10 != rev) return 0;
            rev = newRev;
            x = x/10;
        }
        return rev;
    }
}
```