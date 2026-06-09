### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean backspaceCompare(String S, String T) {
        String finals=finalword(S);
        String finalT=finalword(T);
        return finals.equals(finalT);

    }
    public static String finalword(String s){
        char[] chars=s.toCharArray();
        Stack<Character> stack=new Stack<>();
        StringBuilder stringBuilder=new StringBuilder();

        for(int i=0;i<s.length();i++){
            if(chars[i]=='#'){
                if(!stack.isEmpty())
                    stack.pop();
            }else{
                stack.push(chars[i]);
            }
        }
        while(!stack.isEmpty())
            stringBuilder.append(stack.pop());
        return stringBuilder.toString();
    }
    
}
```