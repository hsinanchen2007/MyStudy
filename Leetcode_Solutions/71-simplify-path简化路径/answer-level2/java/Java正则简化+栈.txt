正则表达式简化路径，栈保存路径的各个目录
```
class Solution {
    public String simplifyPath(String path) {
        path = path.replaceAll("(/)(/*)", "/").replaceAll("^/*", "");
        String[] strings = path.split("/");
        Stack<String> stack = new Stack<>();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < strings.length; i++) {
            if (strings[i].equals("..")) {
                if (!stack.isEmpty())
                    stack.pop();
            } else if (!strings[i].equals(".")) {
                stack.add(strings[i]);
            }
        }
        while (!stack.isEmpty()) {
            sb.insert(0, stack.pop());
            sb.insert(0, '/');
        }
        return sb.length() <= 1 ? "/" : sb.toString();
    }
}
```