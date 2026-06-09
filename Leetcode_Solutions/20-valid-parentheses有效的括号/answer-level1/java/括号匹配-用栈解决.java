### 解题思路
一个好的数据结构省心。
1.用栈解决括号匹配。
2.一一匹配原则，所以排除奇数串，空的也不对。
3.左括号入栈；右括号匹配，出栈，只要不匹配就出错。 完成时，应该栈为空。
4.被忽略的一种情况，全是左括号，用栈非空，再次判断。
5.也同样假如只有右括号，栈是空的，没法出栈，所以出栈的时候要做非空判断，要不报错。我用了‘ ’字符代表栈空，判断了栈空报错的情况。


### 代码

```java
class Solution {
    public boolean isValid(String s) {
        char[] chars = s.toCharArray();
        if (chars.length % 2 != 0) {
            return false;
        }
        if (chars.length == 0) {
            return true;
        }
        boolean result = isInStack(chars);
        return result;
    }

    private boolean isInStack(char[] chars) {
        Stack<Character> left = new Stack<>();
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] == '(' || chars[i] == '[' || chars[i] == '{') {
                left.push(chars[i]);
            } else {
                char leftchar = !left.empty() ? left.pop() : ' ';
                switch (leftchar) {
                    case '(':
                        if (chars[i] != ')') return false;
                        break;
                    case '[':
                        if (chars[i] != ']') return false;
                        break;
                    case '{':
                        if (chars[i] != '}') return false;
                        break;
                    case ' ':
                        return false;
                    default:
                        break;
                }
            }

        }
        if(!left.empty()) return false;
        return true;
    }
}
```