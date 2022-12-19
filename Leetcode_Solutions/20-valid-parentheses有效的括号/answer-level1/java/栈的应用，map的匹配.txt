### 解题思路


### 代码

```java
class Solution {
    public boolean isValid(String s) {
        if (s==null || "".equals(s))
            return true;
         if(s.length()%2!=0)
         return false;
         Stack<Character> stack=new Stack<>();
         Map<Character,Character> map=new HashMap<>();
         map.put(')','(');
         map.put('}','{');
         map.put(']','[');
         for(int i=0;i<s.length();i++)
         {
             char c=s.charAt(i);
             if(!map.containsKey(c))
                {
                    stack.push(c);
                }
                else
                {
                  if(stack.size()==0)   
                    return false;
                Character tmp=stack.pop();
                if(map.get(c)!=tmp)
                    return false;
                }
         }
         return stack.empty();
    }
}
```