### 解题思路
利用栈，先进后出的特性，进行翻转。

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        Stack<String> stack = new Stack<>();
        String[] s1 = s.split(" ");
        for(String str:s1){
            if(!str.isEmpty()) {
                stack.push(str);
            }
        }
        StringBuilder sb = new StringBuilder();
        while(!stack.isEmpty()){
            sb.append(stack.pop().trim()).append(" ");
        }
        return sb.toString().trim();
    }
}
```