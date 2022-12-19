### 解题思路
此处撰写解题思路
用两个栈来存储数据stack、starts。
当数据为'('时存入stack 为 * 时存入 starts
当为')' 先去找与它匹配的')' 没有 就去 starts中找* 再没有就false
当消耗完所有的 * 之后，两个栈中还有数据则表明还有*的存在 
比较*和stack栈中的顶值，将所有stack栈中值弹出，若stack没有值了 则为true
否则为false

### 代码

```java
class Solution {
    public boolean checkValidString(String s) {
      Stack<Integer> stack = new Stack<>();
        Stack<Integer> starts = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
           if (s.charAt(i)=='('){
               stack.push(i);
           } else if(s.charAt(i)==')'){
                if (stack.empty()){
                    if (starts.empty()){
                        return false;
                    } else {
                        starts.pop();
                    }
                } else {
                    stack.pop();
                }
           } else {
               starts.push(i);
           }
        }
        while (!stack.empty()&&!starts.empty()){
            if (stack.peek()<starts.peek()){
                stack.pop();
                starts.pop();
            } else {
                return false;
            }
        }
       if (stack.empty()){
           return true;
       }
       return false;
    }
}
```