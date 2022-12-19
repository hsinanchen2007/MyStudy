### 解题思路
就根据题目描述一步一步处理。需要注意一下**处理边界情况（INT_MAX 和 INT_MIN）**。

处理数字的时候，每次把当前的`res`跟`Integer.MAX_VALUE/10`做个比较，
* 如果比这个值大，那么这次的进位一定会溢出，直接返回最大值就行了。
* 如果相等的话
    * 那么比较一下这次需要加上的末位值是否大于`8`，如果超过，那么这次进位的值也是必定溢出的，直接返回就好。
    * 否则直接做完这次进位操作，返回答案。因为下次进位必定溢出。

代码流程：
1. 处理前置空格
2. 处理正负号
3. 处理数字

### 代码
```java
class Solution {
    public int myAtoi(String str) {
        int res = 0;
        boolean isNegtive = false;
        // int maxPrefix = Integer.MAX_VALUE/10;
        int maxPrefix = 214748364;
       
        int i = 0;
        // 处理前置空格
        while (i < str.length()) {
            if (str.charAt(i) != ' ') break;
            ++i;
        }

        // 处理符号
        if (i >= str.length()) return 0;
        if (str.charAt(i) == '-') {
            isNegtive = true;
            ++ i;
        } else if (str.charAt(i) == '+') {
            ++ i;
        }

        // 处理数字
        while (i < str.length()) {
            char ch = str.charAt(i);
            ++ i;
            // if (!Character.isDigit(ch)) break;
            if (ch < '0' || ch > '9') break;
            if (res > maxPrefix) {
                if (isNegtive) return Integer.MIN_VALUE;
                else return Integer.MAX_VALUE;
            } else if (res == maxPrefix) {
                if (ch >= '8') {
                    if (isNegtive) return Integer.MIN_VALUE;
                    else return Integer.MAX_VALUE;
                } else {
                    res = res * 10 + (ch - '0');
                    break;
                }
            }
            res = res * 10 + (ch - '0');
        }
        if (isNegtive) return -res;
        else return res;
    }
}
```