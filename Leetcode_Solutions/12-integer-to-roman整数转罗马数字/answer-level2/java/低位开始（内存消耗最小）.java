### 解题思路

![1.png](https://pic.leetcode-cn.com/6d43fd776b1274aba7fbea0e3128bd6497b83bcf420b5f0f36c5375faf780d5e-1.png)

麻烦是麻烦了点……全部使用if判断。看代码很好理解。

### 代码

```java
class Solution {
    public String intToRoman(int num) {
        StringBuilder str = new StringBuilder();
        int curr = 1;
        while (num != 0) {
            int n = num % 10;
            if (n % 5 == 4 || n % 5 == 0) {
                if (n == 4 || n == 5) {
                    if (curr == 1) { str.append('V'); }
                    else if (curr == 10) { str.append('L'); }
                    else { str.append('D'); }
                } else if (n == 9){
                    if (curr == 1) { str.append('X'); }
                    else if (curr == 10){ str.append('C'); }
                    else { str.append('M'); }
                }
                if (n % 5 == 4) {
                    if (curr == 1) { str.append('I'); }
                    else if (curr == 10) { str.append('X'); }
                    else if (curr == 100){ str.append('C'); }
                    else { str.append('M'); }
                }
            }else if (n % 5 > 0 && n % 5 < 4) {
                for (int i = 0; i < n % 5; i++) {
                    if (curr == 1) { str.append('I'); }
                    else if (curr == 10) { str.append('X'); }
                    else if (curr == 100){ str.append('C'); }
                    else { str.append('M'); }
                }
                if (n > 5) {
                    if (curr == 1) { str.append('V'); }
                    else if (curr == 10) { str.append('L'); }
                    else { str.append('D'); }
                }
            }
            num /= 10;
            curr *= 10;
        }
        return str.reverse().toString();
    }
}
```