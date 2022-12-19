### 解题思路
其实个人觉得主要是理解这个：先出现的左括号（'('或'['或'{'），其对应的右括号（')'或']'或'}'）肯定后出现；（这里的先出现的左括号指的是：接连出现好几个左括号）
所以选择辅助栈来实现就很简单了
    1. 当遇到'('或'['或'{'，就把对应的右括号push入栈中;
    2. 当遇到右括号时就判断当前栈顶元素是否与其相等，如果相等就证明括号正确匹配，如果不相等就说明不匹配，直接return false即可；
    3. 循环结束都没有返回的话，说明整个字符串中的括号完全匹配，return true
### 代码

```java
class Solution {
    public boolean isValid(String s) {
        if(s.isEmpty()){
            return true;
        }
        Stack<Character> stack=new Stack<>();
        for(char ch:s.toCharArray()){
            if(ch=='('){
                stack.push(')');
            }else if(ch=='['){
                stack.push(']');
            }else if(ch=='{'){
                stack.push('}');
            }else if(stack.empty()||ch!=stack.pop()){
                return false;
            }
        }
        return stack.empty();
    }
}
```