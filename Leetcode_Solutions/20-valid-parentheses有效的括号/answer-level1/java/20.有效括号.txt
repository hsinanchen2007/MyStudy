### 解题思路
如果是"("、"["、"{",则入栈;
如果在循环过程中，栈空则出错;
栈顶元素和下一个字符不匹配出错；
最后返回的是循环结束后，stack.isEmpty(),因为如果循环结束，是空栈则正确，反之就错误

### 代码

```java
class Solution {
  public boolean isValid(String s) {
        Stack<Character> stack= new Stack<Character>();
        char temp;
        for(char c:s.toCharArray()){
            if(c=='('||c=='['||c=='{')
                stack.push(c);
         else  {
            if(stack.isEmpty())
                {return false;}
             temp=stack.pop();
            if((temp=='('&&c!=')')||(temp=='{'&&c!='}')||(temp=='['&&c!=']'))
            {return false;}
            
            }
            
        }
        
        return stack.isEmpty();
        
    }
}
```