### 解题思路

见代码注释

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0) return false; //负数肯定不是回文串
        if(x < 10) return true; //0-9肯定是回文串
        int origin = x;
        int tem = 0;
        //翻转了整数后如果相等，则是回文数
        while(x != 0) {
            int pop = x % 10;
            //反转后如果超出了32位整数值，则不是回文串
            if(tem > Integer.MAX_VALUE / 10 || (tem == Integer.MAX_VALUE / 10 && tem > 7)) {
                return false;
            }
            tem = tem * 10 + pop;
            x /= 10;
        }
        return tem == origin;
    }
}
```