效率不高，所以还是推荐直接用API。。。

```java
class Solution {
    public String reverseWords(String s) {
        
        char[] chs = s.toCharArray();
        int len = chs.length;
        if (len == 0) return "";
        
        int[][] states = {{0, 1},{0, 1}}; // 状态表 0 表示空格状态 1表示字符状态
        int state = 0; // 初始状态为0
        
        Stack<String> stack = new Stack<>();
        StringBuilder word = new StringBuilder();
        for (char ch : chs) {
            state = states[state][getState(ch)]; // 获得ch转换后的下一个状态
            if (state == 0) { // 如果是空格状态
                if (word.length() != 0) stack.push(word.toString()); // 将当前临时串入栈
                word.setLength(0); // 清空临时串
            } else { 
                word.append(ch);
            }
        }
        
        // 单词的出栈顺序就是等同于反转单词
        StringBuilder ans = new StringBuilder(word.toString());
        while (!stack.empty()) {
            if (ans.length() != 0) ans.append(" ").append(stack.pop());
            else ans.append(stack.pop());
        }
        
        return ans.toString();
    }
    
    public int getState(char c) {
        if (c == ' ') return 0;
        else return 1;
    }
}
```