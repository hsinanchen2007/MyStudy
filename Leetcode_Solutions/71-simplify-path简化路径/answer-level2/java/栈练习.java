### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public static String simplifyPath(String path) {
        Stack<String> paths = new Stack<>();
        String[] strs = path.split("/");
        for (int i = 0; i <strs.length ; i++) {
            if ("..".equals(strs[i])&&!paths.empty()){
                paths.pop();
            } else if(!"".equals(strs[i]) && !".".equals(strs[i])&&!"..".equals(strs[i])){
                paths.push(strs[i]);
            }
        }
        StringBuilder sb = new StringBuilder();
        if (paths.empty()){
            return "/";
        }
        for (int i = 0; i < paths.size(); i++) {
            sb.append("/").append(paths.get(i));
        }
        return sb.toString();
    }
}
```