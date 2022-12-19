### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
  private HashMap<Character,Character> mappings;
public Solution (){
    this.mappings= new HashMap<Character, Character>();
    
    this.mappings.put(')','(');
    this.mappings.put('}','{');
    this.mappings.put(']','[');
  }
 public boolean isValid(String s) {
  Stack<Character>stack=new Stack<Character>();
  for(int i=0;i<s.length();i++)
  {
      char c=s.charAt(i);
      if(this.mappings.containsValue(c))
      {
          stack.push(c);
      }
     if(this.mappings.containsKey(c))
          {
              char top=stack.empty()?0:stack.pop();
              if(top!=this.mappings.get(c))
              {
              return false;
             }
          }
      }     
return stack.isEmpty();
  }
  }
  
  


```