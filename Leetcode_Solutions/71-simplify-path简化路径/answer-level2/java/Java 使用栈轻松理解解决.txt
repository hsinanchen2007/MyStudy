### 解题思路
Java 使用栈轻松理解解决

### 代码

```java
class Solution {
    public String simplifyPath(String path) {

            String[] names = path.split("/");
            Stack<String> stack = new Stack<>();
            StringBuffer sb = new StringBuffer();
            for (int i = 0; i < names.length; i++) {
                if ("".equals(names[i]) || ".".equals(names[i])) continue;
                if ("..".equals(names[i]) && stack.size() == 0) continue;

                if ("..".equals(names[i])) {
                    stack.pop();
                    continue;
                }
                stack.push(names[i]);
            }

            if (stack.size() == 0)
                return "/";
                
            for (String str: stack) {
                sb.append("/").append(str);
            }
            return sb.toString();
    }
}
```