#### 思路1：使用Java自带栈
```
括号匹配的问题自然用栈来做，最先想到的是用Java自带的栈来做。是一对，就出栈；
不是一对，就进栈。不需要考虑其他情况，代码比较省事，就是耗时大，有2ms。
```
#### 代码1：耗时2ms
```

public boolean isValid(String s) {
    if(s.length() == 1) 
    	return false;
    Stack<Character> st = new Stack<Character>();
    for (int i = 0; i < s.length(); i++) {
        if (!st.isEmpty() && get(st.peek())==s.charAt(i)) {
            st.pop();
        } else {
            st.push(s.charAt(i));
        }
    }
    return st.isEmpty();
}
	
public char get(char c) {
    switch(c) {
        case '(':
            return ')';
        case '[':
            return ']';
        case '{':
            return '}';
        default:
            return ' ';
    }
}

```
#### 思路2：自己写一个栈
```
和思路1一个流程。考虑到最坏的情况，就是左边全是左括号，所以栈的大小设计成字符串
的一半长度，如果栈有溢出，铁定不匹配，所以加了个try-catch，有异常就返回false。
```
#### 代码2：耗时1ms
```
public boolean isValid(String s) {
    if (s.length() == 1)
        return false;

    char[] stack = new char[(s.length() + 1)/2];
    int top = -1;
    
    for (int i = 0; i < s.length(); i++) {
        if (top != -1 && get(stack[top]) == s.charAt(i)) {
             top--;
        } else {
            try {
                stack[++top] = s.charAt(i);
            } catch (ArrayIndexOutOfBoundsException e) {
                 return false;
            }
        }
    }
    return top == -1;
}

public char get(char c) {
    switch (c) {
        case '(':
            return ')';
        case '[':
            return ']';
        case '{':
            return '}';
        default:
            return '';
    }
}
```

#### 思路3：改良版的自写栈
```
思路2的栈只需要憨进憨出就可以了，其他啥也不考虑。耗时足足有1ms，所以为了减少耗时，
就有了改良版。
让栈中元素保持只有左括号的状态，对象来了，就出栈，如果来的是别的左括号的对象，那就
不行了，直接返回flase结束。
```
#### 代码3：耗时0ms
```
public boolean isValid(String s) {
    if (s.length() <= 0) {
        return true;
    }
    char[] str = s.toCharArray();

    if (s.length() == 1 || (str[0] != '(' && str[0] != '[' && str[0] != '{'))
        return false;

    char[] stack = new char[(s.length() + 2) / 2];
    int top = -1;

    for (char c : str) {
    switch (c) {//用if写也OK，个人感觉用switch-case思路跟清晰
      	case '(':
        case '[':
        case '{':
        	stack[++top] = c;
        	break;
        case ')': 
            if (top == -1 || stack[top] != '(') {
                return false;
            }
            --top;
            break;
        case ']':
            if (top == -1 || stack[top] != '[') {
                return false;
            }
            --top;
            break;
        case '}':
            if (top == -1 || stack[top] != '{') {
            	return false;
            }
            --top;
            break;
        }
    }
    return top == -1;
}
```

