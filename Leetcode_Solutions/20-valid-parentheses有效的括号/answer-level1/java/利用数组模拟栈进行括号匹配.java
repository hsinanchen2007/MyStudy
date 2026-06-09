### 解题思路
此处撰写解题思路

### 代码

```java
public class Solution {
    public boolean isValid(String s) {
        if(s.length() == 0)//如果是空字符串，则有效
            return true;
        if(s.length()%2 == 1)//如果字符串的长度是奇数个，则无效
            return false;
        int index = -1;//栈的索引值
        char[] stack = new char[s.length()];//用数组模拟栈

        for (int i = 0; i < s.length(); i++) {
            switch (s.charAt(i)){
                case '(':
                case'[':
                case '{':
                    stack[++index] = s.charAt(i);//进栈
                    continue;
                case ')':
                    if(index == -1 || stack[index--] != '(')
                        return false;
                    continue;
                case ']':
                    if(index == -1 || stack[index--] != '[')
                        return false;
                    continue;
                case '}':
                    if(index == -1 || stack[index--] != '{')
                        return false;
                    continue;

            }
        }
        return index == -1;
    }
}
```