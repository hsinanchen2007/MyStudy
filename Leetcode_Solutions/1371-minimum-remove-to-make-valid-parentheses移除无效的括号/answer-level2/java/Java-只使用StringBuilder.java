# 思路
维护1个计数器，遇到'('则计数器+1，遇到')'则计数器-1。
若计数器的值为负，说明额外多出')'，删除')'，并将计数器置为0.
若最终计数器的值为正，说明额外多出'('，**从右往左**删除'('。
为何是**从右往左**删除'('?因为是**从左往右**遍历。

# 代码
```java
class Solution {
    public String minRemoveToMakeValid(String s) {
        StringBuilder res = new StringBuilder(s);
        int count = 0;
        for (int i = 0; i < res.length(); ++i)
            if (res.charAt(i) == '(')
                ++count;
            else if (res.charAt(i) == ')' && --count < 0) {
                count = 0;
                res.deleteCharAt(i--);
            }

        while (--count > -1)
            res.deleteCharAt(res.lastIndexOf("("));
        return res.toString();
    }
}
```
