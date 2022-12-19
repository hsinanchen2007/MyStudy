### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String removeOuterParentheses(String S) {
        
  char[] c = S.toCharArray();//把字符串转成字符数组
        int left=0;//用来记位str最左边的位置
        Stack<Character> stack = new Stack<Character>();//定议一个栈
        StringBuilder str = new StringBuilder();//定义一个这个，是为了把字符数组存在这里。然后根据栈是否为空删除字符进而的最外层括号
        for(int i=0;i<c.length;i++){
            str.append(c[i]);//进入循环我们就把字符往str里装
            if(c[i]==')'){//判断当前  这个字符是不是）
            if(stack.peek()=='('){//是右括号了，我们看栈顶是不是左括号。能不能配对。能，我们就将栈顶元素删除
                stack.pop();
                if(stack.isEmpty()){//看这个栈是不是空了。空了说明我们到最外层了
                    str.deleteCharAt(left);//我们将str里存放的最左也就是最外层的（删除
                    str.deleteCharAt(str.length()-1);//然后我们将str里存放的最右也就是最外层的）;这就删除 了最外层的一对括号 了
                    left=str.length();//最后，我们让str的最左这个索引指向我们现在str最右的位置。方便下次次我们如果 栈如果 为空了。我们好删除下一组最外层的左括号
                }
            }
            }else {
                stack.push(c[i]);//如果 不是）括号 ，压入栈中
            }
        }
        return str.toString();
    }
}
```