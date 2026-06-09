### 解题思路

     首先排除干扰的 / ，这个问题就好理解多了。
     输入的路径分为3种，第一种：. ，代表当前目录；第二种：..，代表父目录；第三种：正常路径
      1. 将输入的路径按照 / 分割。
      2. 分割后就剩下空字符串，.，..，正常路径4中情况。
      3. 空字符串 和 . 可直接忽略。因为空字符串就是路径前或多个/之间的没有实际意义，.代表当前路径。
      4. 利用栈结构，将正常路径压栈。
      5. 如果是..，则表示其父目录，弹出栈顶路径。
      6. 最后，如果栈为空，则返回/；否则，则按照路径拼接。

### 代码

```java
class Solution {
    public String simplifyPath(String path) {
         if (path == null || path.length() < 1) {
            return "";
        }
        Stack<String> stack = new Stack<>();

        String[] pathArr = path.split("/");
        for (String p : pathArr) {
            if (".".equals(p) || p.length() < 1) {
                continue;
            }
            if ("..".equals(p)) {
                if (!stack.empty()) {
                    stack.pop();
                }
            } else {
                stack.push(p);
            }
        }
        if (stack.empty()) {
            return "/";
        }
        StringBuilder fPath = new StringBuilder();
        for (String p : stack) {
            fPath.append("/").append(p);
        }
        return fPath.toString();
    }
}
```