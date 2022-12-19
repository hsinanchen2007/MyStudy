```
public class Solution {
    public bool BackspaceCompare(string S, string T) {
        Stack<char> s = new Stack<char>();
            Stack<char> t = new Stack<char>();
            foreach(char a in S)
            {
                if(a!='#')
                {
                    s.Push(a);
                }
                if(a=='#'&&s.Count()!=0)
                {
                    s.Pop();
                }
            }
            foreach (char a in T)
            {
                if (a != '#')
                {
                    t.Push(a);
                }
                if (a == '#' && t.Count() != 0)
                {
                    t.Pop();
                }
            }
            if(s.Count()!=t.Count())
            {
                return false;
            }
            else
            {
                while(s.Count()>0)
                {
                    if(s.Pop()!=t.Pop())
                    {
                        return false;
                    }
                }
                return true;
            } 
    }
}
```
