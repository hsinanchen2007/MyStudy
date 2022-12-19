### 解题思路
当左括号计数为1时说明是最外层的左括号
当左括号数与右括号数相同时则说明是最外层的右括号

### 代码

```java
class Solution {
    public String removeOuterParentheses(String S) {
        char[] c = S.toCharArray();
        StringBuffer sb = new StringBuffer();
        int l = 0; // 记录左括号个数
        int r = 0; // 记录右括号个数
        for (int i = 0; i < c.length; ++i) {
            // 计数
            if (c[i] == '(') {
                ++l;
            } else {
                ++r;
            }
            // 当左右括号数相同时说明是最外层的右括号
            if (l == r) {
                // 重新计数
                l = r = 0;
                continue;
            }
            // 左括号只有一个时说明是最外层的左括号
            if (l > 1) {
                sb.append(c[i]);   
            }
        }
        return sb.toString();
    }
}
```