### 解题思路
主要想法就是，当遇到左括号‘（’时候入栈，当遇到右括号‘）’时候出栈一个左括号‘（’，当出栈的不是栈顶的‘（’时候填入数组，最后将数组转成string输出。

### 代码

```csharp
public class Solution {
    public string RemoveOuterParentheses(string S) {
        char[] res = new char[S.Length];
        int count = 0;
        int j=0;
        for(int i = 0; i < S.Length; i++)
        {
            if(S[i]=='(') count++;
            if(count!=0&&count!=1)//不是栈顶，输出其中的内容
            {
                res[j++]=S[i];
                if(S[i]==')') count--;//输出右括号时候把指针往退一位
                
            }else if(S[i]==')')//栈顶，推出左括号但是不输出
            {
                count--;
            }
        }
        return new string(res,0,j);
    }
}
```