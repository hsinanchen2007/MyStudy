### 解题思路
依次取出元素，如果是左边括号（‘(，[,{’）,那么直接入栈即可，都认为是符合结果的，当右边括号（‘)，],}’）出现时，那么需要和栈顶比较看是否可以匹配成一对，如果可以，那么继续循环+栈顶出栈（栈不为空，如果为空return false），如果不可以，那么直接返回false。

此题可以优化为：当左边括号出现时，直接将对应的右边括号入栈，这样当右边括号出现时，直接和pop()结果比较相等即可。遍历完成后，如果栈是空的，那么括号肯定是成对出现的。

### 代码

```java
class Solution {
    public boolean isValid(String s) {
        if (s.length()%2 > 0) return false;
        Stack<Character> stack = new Stack<Character>();
        for (char e: s.toCharArray()){
            if (e == '('){
                stack.push(')');
            }else if (e == '{'){
                stack.push('}');
            }else if (e == '['){
                stack.push(']');
            }else{
                if(stack.isEmpty()||e != stack.pop()){
                    return false;
                }
            }
        }
        if(stack.empty())
            return true;
        return false;
    }
}
```