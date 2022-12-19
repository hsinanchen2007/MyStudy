```

public class Solution {
    public string ReverseOnlyLetters(string S) {
            Stack<char> cc = new Stack<char>(); 
            char[] c = S.ToCharArray(); 
            for (int i = 0; i < S.Length; i++)
            {
                if (char.IsLetter(S[i]))
                {
                    cc.Push(S[i]);
                }
            } 
            for (var i = 0; i < c.Length; i++)
            {
                if (char.IsLetter(c[i]))
                    c[i]= cc.Pop();
            }
            return new string(c);
    }
}

```
一个栈存入字符串。反加入即可
