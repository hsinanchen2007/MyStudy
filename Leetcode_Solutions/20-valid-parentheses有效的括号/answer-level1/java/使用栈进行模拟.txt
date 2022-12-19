### 解题思路
括号必须是成对出现出现了"(",必须有一个")"对应才会属于有效的,用栈进行保存,"("当遇到")"时候栈顶的元素必须是"("相对应,否则将不是有效的括号

### 代码

```java
import java.util.*;
class Solution {
    public boolean isValid(String s) {
        //如果是奇数不要在判断了直接返回不满足,因为是成对出现的
        if(s.length()%2!=0){
            return false;
        }
        Map<Character,Character> map=new HashMap<>();
        map.put('(',')');
        map.put('{','}');
        map.put('[',']');
        Stack<Character> stack=new Stack<>();
        for(char c:s.toCharArray()){
            //如果栈是空,直接放元素进去
            if(stack.isEmpty()){
                stack.push(c);
            }else{
                //如果是左括号类的,放进栈中
                if(map.containsKey(c)){
                    stack.push(c);
                }else{
                    //如果不是左括号类型,需要判断是否和栈顶元素是一对,如果是一对弹出栈顶元素,不是说明不是有效的括号直接返回false
                    if(map.get(stack.peek())==null||map.get(stack.peek())!=c){
                        return false;
                    }
                    stack.pop();
                }
            }
        }
        return stack.isEmpty();
    }
}
```