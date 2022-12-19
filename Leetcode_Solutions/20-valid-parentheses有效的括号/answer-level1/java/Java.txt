### 解题思路
练习了栈的使用，需要注意的是char型字符初始化用的是单引号，string是双引号。
### 代码

```java
class Solution {
    public static boolean isValid(String s) {
        Stack<Character> stack = new Stack();
        if(s==null){
            return true;
        }
        Map<Character,Character> map = new HashMap()
        {{
            put(')','(');
            put('}','{');
            put(']','[');
        }};
        int length = s.length();
        for(int i =0;i<length;i++){
            if(s.charAt(i)== '(' || s.charAt(i)=='[' || s.charAt(i)=='{'){
                stack.push(s.charAt(i));
            }else{
                if(stack.empty() || !map.get(s.charAt(i)).equals(stack.pop())){
                    return false;
                }
            }
        }
        if(stack.empty()){
            return true;
        }else{
            return false;
        }
    }
}
```