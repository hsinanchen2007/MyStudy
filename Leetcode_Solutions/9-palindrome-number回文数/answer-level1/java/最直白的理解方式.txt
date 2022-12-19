### 解题思路
只有做算法的时候，你才能深刻的认识到自己就是一个智障。。。。

这道题的理解方式和整数反转的理解方式一样，先把数字反转，再和初始值比较，相同则是，相反则否

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }
        int num = x;
        int res = 0;
        while (num != 0)
        {
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res == x?true:false;
    }
}
```