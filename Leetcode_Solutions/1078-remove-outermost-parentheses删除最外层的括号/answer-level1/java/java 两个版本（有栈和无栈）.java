### 解题思路
有栈：通过栈是否非空来进行判断

### 代码

```java
class Solution {
    public String removeOuterParentheses(String S) {
        Stack<Character> sta1 = new Stack<Character>();
        StringBuilder sb=new StringBuilder();
        for(char c :S.toCharArray()){
            if(c== '('){
                if(!sta1.isEmpty())
                    sb.append(c);
                sta1.push(c);
            } else{
                sta1.pop();
                if(!sta1.isEmpty())
                    sb.append(c);
            }
        }
        return sb.toString();
    }
}
```
### 解题思路
无栈：通过左括号的个数来进行判断

### 代码

```java
class Solution {
    public String removeOuterParentheses(String S) {
        StringBuilder sb=new StringBuilder();
        int left = 0;
        for(char c :S.toCharArray()){
            if(c== '(' && left++ > 0) sb.append(c);
            else if(c == ')' && --left>0) sb.append(c);
        }
        return sb.toString();
    }
}
```