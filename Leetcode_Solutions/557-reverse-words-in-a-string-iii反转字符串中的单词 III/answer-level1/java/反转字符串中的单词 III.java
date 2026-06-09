### 解题思路
    将单词倒序输出，很容易想到栈这种数据结构，在Java语言中，有栈的包，可以调用。
当我们新建一个字符串时，可以用StringBuilder 类中的函数。向StringBuilder对象中添加元素使用
append函数即可。最后将StringBuilder类对象转化为String时需要使用.toString()函数。
    当然，用栈这种数据结构解题的时间复杂度和空间复杂度都比较高。

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        Stack <Character> stack=new Stack<Character>();
        StringBuilder sb=new StringBuilder();
        for(char ch:s.toCharArray())
        {
            if(ch!=' ')             //只要不是空，说明一个单词没有结束，入栈
                stack.push(ch);
            else if(ch==' ')        //一个单词结束标志为空格，因此遇到空格弹栈，反转单词
            {
                while(!stack.isEmpty())  //栈不空时就将栈顶的元素弹出
                {
                    sb.append(stack.pop());
                }
                sb.append(ch);
            }
        } 
        while(!stack.isEmpty())       //别忘了字符串的结尾没有空格，还需要弹栈一次。
                sb.append(stack.pop());
        return sb.toString();
    }
}
```