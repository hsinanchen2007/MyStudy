### 解题思路

![批注 2020-02-12 102340.png](https://pic.leetcode-cn.com/2fd068b8d41573e007ff04d022a30c7c36540574c2d20a121824af4a76d72d32-%E6%89%B9%E6%B3%A8%202020-02-12%20102340.png)

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') ans.append("%20");
            else ans.append(s.charAt(i));
        }
        return ans.toString();
    }
}
```