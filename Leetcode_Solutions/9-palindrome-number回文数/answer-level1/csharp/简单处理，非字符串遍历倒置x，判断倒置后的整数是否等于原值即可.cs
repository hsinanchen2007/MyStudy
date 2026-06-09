![image.png](https://pic.leetcode-cn.com/cedb355710e83b8779fe149ac1b0a92caae15479b1d35d4475f0aa587636c12d-image.png)
### 解题思路
1. 判断特殊情况:
  - x为负数返回false；
  - x小于10返回true；
2. 定义n储存计算前的x，y为x除10取余；
3. 循环x除10赋值本身，y乘10加上x除10取余，直到x小于10
4. 返回y是否等于n即可判断为回文。

### 代码

```csharp
public class Solution {
    public bool IsPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        int n = x, y = x % 10;
        while (x >= 10)
        {
            x /= 10;
            y = y * 10 + x % 10;
        }
        return y == n;
    }
}
```