### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        if(s.length() == 0)
            return "";

        s = s.trim();
        s = s.replaceAll("\\s+", " ");
        StringBuilder sb = new StringBuilder();
        char[] chars = s.toCharArray();
        Stack<String> stack = new Stack<String>();
        int start = 0;
        for(int i = 0; i < chars.length; i++){
            if(chars[i] == ' '){
                stack.push(s.substring(start, i));
                start = i + 1;
            }
        }
        stack.push(s.substring(start, s.length()));
        while(!stack.isEmpty()){
            sb.append(stack.pop());
            sb.append(" ");
        }
        return sb.toString().trim();
    }
}
```