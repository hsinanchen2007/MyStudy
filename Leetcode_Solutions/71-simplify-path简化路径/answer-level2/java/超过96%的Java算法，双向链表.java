这道题，天然看起来使用栈即可，最后打印结果有需要顺序遍历，所以使用双向链表是最好的方式

```Java
class Solution {
    public String simplifyPath(String path) {
        LinkedList<String> stack = new LinkedList<>();
        String[] array = path.split("/");
        
        for (int i = 0; i < array.length; i++) {
            String s = array[i];
            if (s.equals("") || s.equals(".")) {
                continue;
            } else if (s.equals("..")) {
                if (!stack.isEmpty()) {
                    stack.removeLast();
                }
            } else {
                stack.add(s);
            }
        }
        
        if (stack.isEmpty()) {
            return "/";
        }
        
        StringBuilder sb = new StringBuilder();
        
        for (String item : stack) {
            sb.append("/" + item);
        }
        return sb.toString();
    }
}
```