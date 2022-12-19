直接用数组
执行用时 :
2 ms
, 在所有 java 提交中击败了
100.00%
的用户
内存消耗 :
37.5 MB
, 在所有 java 提交中击败了
73.96%
的用户
```
public String removeOuterParentheses(String S) {
        StringBuffer buffer=new StringBuffer();
        char[] chars=new char[S.length()];
        int index=-1;
        for (char c:S.toCharArray()) {
            if (index==-1) {
                chars[++index]=c;
            }else {
                if (c=='(') {
                    chars[++index]=c;
                    buffer.append(c);
                }else{
                    index--;
                    if (index>-1) {
                    buffer.append(c);
                }
                }
                
            }
        }
        return buffer.toString();
    }
```
栈
7 ms	35.8 MB	Java
```
public String removeOuterParentheses(String S) {
        StringBuffer buffer=new StringBuffer();
        Stack<Character> stack=new Stack<Character>();
        for (char c:S.toCharArray()) {
            if (stack.isEmpty()) {
                stack.push(c);
            }else {
                if (c=='(') {
                    stack.push(c);
                    buffer.append(c);
                }else{
                    stack.pop(); 
                    if (!stack.isEmpty()) {
                        buffer.append(c);
                    }
                }
            }
        }
        return buffer.toString();
    }
```
不用数组和栈
执行用时 :
2 ms
, 在所有 java 提交中击败了
100.00%
的用户
内存消耗 :
37.4 MB
, 在所有 java 提交中击败了
75.00%
的用户
```
public String removeOuterParentheses(String S) {
        StringBuffer buffer=new StringBuffer();
        int index=0;
        for (char c:S.toCharArray()) {
                if (c=='(') {
                    index++;
                    if (index>1) {
                        buffer.append(c);
                    }
                }
                if(c==')'){
                    index--;
                    if (index>0) {
                        buffer.append(c);
                    }
                }
        }
        return buffer.toString();
    }
```

不用数组和栈简洁
执行用时 :
2 ms
, 在所有 java 提交中击败了
100.00%
的用户
内存消耗 :
37.4 MB
, 在所有 java 提交中击败了
75.52%
的用户
```
public String removeOuterParentheses(String S) {
        StringBuffer buffer = new StringBuffer();
        int index = 0;
        for (char c : S.toCharArray()) {
            if (c == ')') {
                index--;
            }
            if (index > 0) {
                buffer.append(c);
            }
            if (c == '(') {
                index++;
            }

        }
        return buffer.toString();
    }
```
