- ![clipboard.png](https://pic.leetcode-cn.com/de3ec62b42edb3c2272b3c029f5530634cb7efc52742252573f75a5d869bd776-clipboard.png)

```
class Solution {
    public String simplifyPath(String path) {
        if (path == null || path.length() == 0) {
            return "/";
        }
        LinkedList<String> list = new LinkedList<>();
        StringBuilder strBuilder = new StringBuilder();
        for (int i = 0; i < path.length(); i ++) {
            char c = path.charAt(i);
            if (c == '/') {
                if (strBuilder.length() > 0) {
                    dealStr(list, strBuilder.toString());
                    strBuilder.delete(0, strBuilder.length());
                }
            }
            else {
                strBuilder.append(c);
            }
        }
        // 最后可能余留字符串处理
        if (strBuilder.length() > 0) {
            dealStr(list, strBuilder.toString());
            strBuilder.delete(0, strBuilder.length());
        }

        // 拼接结果字符串
        for (String str: list) {
            if (strBuilder.length() > 0) {
                strBuilder.append('/');
            }
            strBuilder.append(str);
        }
        return '/' + strBuilder.toString();
    }

    private void dealStr(LinkedList<String> list, String str) {
        if (".".equals(str)) {
            // Empty
        }
        else if ("..".equals(str)) {
            if (!list.isEmpty()) {
                list.removeLast();
            }
        }
        else {
            list.add(str);
        }
    }
}
```
